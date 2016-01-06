# ベンチャー体験工房

## main.py
- main

## search.py
- doPrint()
> Check whether display an user or not.

- isValidUser(uid)
> Check whether an user id is valid or invalid.

- search(info)
> Find an user by the user id.

- searchUserId(uid)
> Search by an user id.

- getUsers(url)
> Get users.

- displayUser(user)
> Display user information.

## uinfo.py
- Class User(userID, userName, affiliation, probNum, problems[])
- init
- setter, getter

- Class Users(users[])
  - init
  - isUser(user)
  - append(user)
  - remove(user)
  - printUsers()
  - searchUser(user)
  - sort(base)
  - mergeUsers(users)

## aoj.py
- Class MyAPI
  - doPrint()
  > Check whether display an user information or not.

  - isValidUser(uid)
  - getUserDiff(u1, u2)
  - searchCloseUser(num, diff)
  - searchNextProblem()
  - getSimilarUser(user, offset)
