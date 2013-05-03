################################################################################
#	MODULE	:	tools_env.mk
#	PROJECT	:	Build Scripts
#	AUTHOR	:	Michael Uman
#	DATE	:	April 22, 2013
################################################################################

ARCH ?= $(shell uname -m)
DIST ?= $(shell lsb_release -cs)

GPP ?= g++
GCC ?= gcc
AR  ?= ar
TAR ?= tar

