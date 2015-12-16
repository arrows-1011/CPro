# -*- coding:utf-8 -*-

# User's information module

# An user has plenty of information such as
# user id, user name, affiliation, the number of probrem,
# and problems that its user already solved.


# An user information
class User(object):
    userID = ""
    userName = ""
    affiliation = ""
    probNum = 0
    problems = []

    def __init__(self):
        self.userID = ""
        self.userName = ""
        self.affiliation = ""
        self.probNum = 0
        self.problems = []

    def setUserID(self, userID):
        self.userID = str(userID)

    def getUserID(self):
        return self.userID

    def setUserName(self, userName):
        self.userName = str(userName)

    def getUserName(self):
        return self.userName

    def setAffiliation(self, affiliation):
        self.affiliation = str(affiliation)

    def getAffiliation(self):
        return self.affiliation

    def setProbNum(self, probNum):
        self.probNum = str(probNum)

    def getProbNum(self):
        return self.probNum

    def setProblems(self, problems):
        self.problems = problems

    def getProblems(self):
        return self.problems


# Users information
class Users(object):
    users = []

    def __init__(self):
        self.users = []

    def isUser(self, user):
        return isinstance(user, User)

    def append(self, user):
        if self.isUser(user) is False:
            return

        if self.searchUser(user) is False:
            self.users.append(user)

    def remove(self, user):
        if self.isUser(user) is False:
            return

        if self.searchUser(user) is True:
            self.users.remove(user)

    def printUsers(self):
        for user in self.users:
            print(user)

    def searchUser(self, user):
        if self.isUser(user) is False:
            return False

        if self.users.count(user) > 0:
            return True
        else:
            return False

    def sort(self, base):
        if base == "ID":
            sorted(self.users, key=lambda x: x.self.users.userID)
        elif base == "solved":
            sorted(self.users, key=lambda x: x.self.users.probNum)

    # Merge two lists
    def mergeUsers(self, users):
        if isinstance(users, Users) is False:
            return

        for user in users:
            self.append(user)
