# -*- coding:utf-8 -*-

import sys
import urllib.request
import usr
import xml.etree.ElementTree as ET


def doPrint():
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


# Check whether user id is valid or invalid
def isValidUser(uid):
    for i in range(len(uid)):
        if ('a' <= uid[i] and uid[i] <= 'z'):
            continue
        elif ('A' <= uid[i] and uid[i] <= 'Z'):
            continue
        elif ('0' <= uid[i] and uid[i] <= '9'):
            continue
        elif uid[i] == '_':
            continue
            return False

    return True


# Find user by an user id
def search(info):
    return searchUserId(info)


# Search by an user id
def searchUserId(uid):
    if uid == "":
        print("Please input an user id.")
        uid = input()

    # Check whether an user id is valid or invalid
    if isValidUser(uid) is False:
        sys.exit("Invalid user id")

    url = "http://judge.u-aizu.ac.jp/onlinejudge/webservice/user?id="\
          + str(uid)

    return getUsers(url)


# Get users
def getUsers(url):
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
    user = usr.User()
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

    if doPrint():
        displayUser(user)

    return user


# Display an user
def displayUser(user):
    # Display user information
    print("ID: " + user.getUserID())
    print("Name: " + user.getUserName())
    print("Affiliation: " + user.getAffiliation())
    print("The number of accepted: " + user.getProbNum())
    print("\nList solved problems:")
    print(' '.join(user.getProblems()))
