import getpass
file = open("username.txt", "w")
file.write(getpass.getuser())
file.close()
