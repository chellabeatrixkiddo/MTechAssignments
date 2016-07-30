# Makefile for VFS Demo
all: vfs_create_driver vfs_ops_driver
vfs_create_driver: vfs_create_driver.o vfs_create.o
	gcc -o vfs_create_driver vfs_create_driver.o vfs_create.o
vfs_create_driver.o: vfs_create_driver.c vfs.h
	gcc -c vfs_create_driver.c
vfs_create.o: vfs_create.c vfs.h
	gcc -c vfs_create.c
vfs_ops_driver: vfs_ops_driver.o vfs_ops.o
	gcc -o vfs_ops_driver vfs_ops_driver.o vfs_ops.o
vfs_ops_driver.o: vfs_ops_driver.c vfs.h
	gcc -c vfs_ops_driver.c
vfs_ops.o: vfs_ops.c vfs.h
	gcc -c vfs_ops.c
