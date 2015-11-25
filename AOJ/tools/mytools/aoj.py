# -*- coding:utf-8 -*-

import sys
import uinfo
import urllib.request
import xml.etree.ElementTree as ET


class MyAPI(object):
    # Check whether user name is valid or invalid
    def isValidUser(self, name):
        for i in range(len(name)):
            if ('a' <= name[i] and name[i] <= 'z'):
                continue
            elif ('A' <= name[i] and name[i] <= 'Z'):
                continue
            elif ('0' <= name[i] and name[i] <= '9'):
                continue
            elif name[i] == '_':
                continue
            return False

        return True

    # Get the user information
    def userSearch(self, ID):
        # print("--In userSearch--")
        if ID == "":
            print("Please input your user ID")
            ID = input()

        # Check whether ID is valid or invalid
        if self.isValidUser(ID) is False:
            sys.exit("Invalid user name")

        # Split url because they're long (over 80 words)
        url = "http://judge.u-aizu.ac.jp/onlinejudge/webservice/user?id="\
              + str(ID)

        request = urllib.request.Request(url)
        response = urllib.request.urlopen(request)

        # Check status code
        if response.getcode() != 200:
            sys.exit("Invalid response")

        # parse
        tree = ET.parse(response)
        root = tree.getroot()
        found = 0
        isProb = 0
        user = uinfo.User()
        problems = []
        for e in root.getiterator():
            if e.tag == "id" and found == 0:
                found = 1
                user.setUserID(e.text)
            elif e.tag == "name":
                user.setUserName(e.text)
            elif e.tag == "affiliation":
                user.setAffiliation(e.text)
            elif e.tag == "solved":
                user.setProbNum(e.text)
            elif e.tag == "id" and isProb == 1:
                problems.append(e.text)

            if found == 1:
                isProb = 1

        user.setProblems(problems)

        if self.doPrint():
            # Display user information
            print("ID: " + user.getUserID())
            print("Name: " + user.getUserName())
            print("Affiliation: " + user.getAffiliation())
            print("The number of accepted: " + user.getProbNum())
            print("\nList solved problems:")
            print(' '.join(user.getProblems()))

        return user

    def doPrint(self):
        # return False
        print("Do you want to display the user information? (yes/no)")

        while True:
            state = input()
            if state == "yes" or state == "no":
                break
            else:
                print("Please input yes or no")

        print("")

        if state == "yes":
            return True
        else:
            return False

    # Get the difference between users
    def getUserDiff(self, u1, u2):
        # print("In getUserDiff")
        user1 = self.userSearch(u1)
        user2 = self.userSearch(u2)
        probOnlyUser1 = []
        probOnlyUser2 = []
        probBothUsers = []
        prob1 = user1.getProblems()
        prob2 = user2.getProblems()
        id1 = user1.getUserID()
        id2 = user2.getUserID()

        for p in prob1:
            if prob2.count(p) > 0:
                probBothUsers.append(p)
            else:
                probOnlyUser1.append(p)

        for p in prob2:
            if prob1.count(p) == 0:
                probOnlyUser2.append(p)

        if self.doPrint():
            # Display both users solved
            print("Solved both " + id1 + " and " + id2 + " is " +
                  str(len(probBothUsers)) + " problems")
            print(' '.join(probBothUsers) + '\n')

            # Display user1 solved only
            print("Solved only " + id1 + " is " +
                  str(len(probOnlyUser1)) + " problems")
            print(' '.join(probOnlyUser1) + '\n')

            # Display user2 solved only
            print("Solved only " + id2 + " is " +
                  str(len(probOnlyUser2)) + " problems")
            print(' '.join(probOnlyUser2) + '\n')

        return len(probBothUsers)/len(prob1)

    # Get ids of ([num-diff, num+diff])
    def searchCloseUser(self, num, diff):
        # print("--In searchCloseUser--")
        num = str(num)
        # Check whether the probNum is valid or invalid
        for i in range(len(num)):
            if ('0' <= num and num <= '9'):
                continue
            sys.exit("Invalid values")

        if int(num) - diff < 0:
            sys.exit("Invalid values")

        # Split url because they're long (over 80 words)
        url = "http://judge.u-aizu.ac.jp/onlinejudge/webservice/"\
              "user_list?solved_min=" + str(int(num)-diff) + "&"\
              "solved_max=" + str(int(num)+diff)

        request = urllib.request.Request(url)
        response = urllib.request.urlopen(request)

        # Check status code
        if response.getcode() != 200:
            sys.exit("Invalid response")

        tree = ET.parse(response)
        root = tree.getroot()
        users = []
        for elem in root.getiterator("id"):
            s = ""
            for e in elem.text:
                if e != '\n':
                    s += e

            users.append(s)

        if self.doPrint():
            for e in users:
                print(e)
        return users

    # Search problems that the user should solve
    def searchNextProblem(self):
        counter = {}  # counter[problem number] := the number of solved
        myUser = self.userSearch("")

        users = self.searchCloseUser(myUser.getProbNum(), 100)
        myList = myUser.getProblems()
        for u in users:
            user = self.userSearch(u)
            userList = user.getProblems()
            for p in userList:
                if myList.count(p) == 0:
                    if str(p) in counter:
                        counter[str(p)] += 1
                    else:
                        counter[str(p)] = 1

        cur = 0
        for key, value in sorted(counter.items(),
                                 key=lambda x: x[1], reverse=True):
            cur += 1
            print(key, value)
            if cur == 15:
                break

    # Search a similar user
    def getSimilarUser(self, user, offset):
        if offset == -1:
            offset = int(input())
        users = self.searchCloseUser(user.getProbNum(), offset)
        res = 0
        similarUser = ""
        for u in users:
            if user.getUserID() == u:
                continue

            diff = self.getUserDiff(user.getUserID(), u)
            if res < diff:
                res = diff
                similarUser = u

        return similarUser, res
