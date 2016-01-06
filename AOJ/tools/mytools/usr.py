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
