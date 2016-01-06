# -*- coding:utf-8 -*-

import aoj
import usrs

if __name__ == "__main__":
    myAPI = aoj.MyAPI()
    # myAPI.searchNextProblem()
    # print(myAPI.getSimilarUser(myAPI.userSearch("s1210207"), 200))
    # myAPI.searchNextProblem()
    # print(myAPI.getUserDiff("s1210207", ""))

    arr = usrs.Users()
    arr.append("s1210207", 1)
    arr.printUsers()
