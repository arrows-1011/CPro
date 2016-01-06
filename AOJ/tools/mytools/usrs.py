# -*- coding:utf-8 -*-

import search as srh
import usr


# Users information
class Users(object):
    users = []

    def __init__(self):
        self.users = []

    def isUser(self, user):
        return isinstance(user, usr.User)

    def append(self, info, num):
        if num == 0:
            user = info
            if self.searchUser(user) is True:
                self.users.append(user)

        elif num == 1:
            userId = info
            user = srh.searchUserId(userId)
            return self.append(user, 0)

    def remove(self, user):
        if self.isUser(user) is False:
            return

        if self.searchUser(user) is True:
            self.users.remove(user)

    def printUsers(self):
        for user in self.users:
            srh.displayUser(user)
            print("")

    def searchUser(self, user):
        if self.isUser(user) is False:
            return False

        if self.users.count(user) > 0:
            return False
        else:
            return True

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
