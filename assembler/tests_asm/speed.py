#!/usr/bin/env python3

import sys
import os
import os.path
from os import path
import subprocess
import time
from subprocess import run

EOC = "\033[0m"
GREEN = "\033[38;5;70m"
RED  = "\033[38;5;124m"
YELLOW = "\033[38;5;220m"
SALMON  = "\033[38;5;203m"
RUST = "\033[38;5;130m"
CYAN = "\033[38;5;43m"
GRAY = "\033[38;5;240m"
WHITE = "\033[38;5;231m"
ITALIC = "\033[3m"

real_asm = "./asm"
your_asm = "../../asm"

if len(sys.argv) != 1:
	print(YELLOW + "Usage:\n  " + EOC + "python3 speed.py")
	sys.exit()

def timeRealAsm(s_file):
	cmd = "./asm %s > /dev/null" % s_file
	proc  =  subprocess.Popen(cmd,shell=True)
	timeStarted = time.time()
	proc.communicate()
	realAsmTotalTime = time.time() - timeStarted
	return (realAsmTotalTime)

def timeYourAsm(s_file):
	cmd = "%s %s  > /dev/null" % (your_asm, s_file)
	proc  =  subprocess.Popen(cmd,shell=True)
	timeStarted = time.time()
	proc.communicate()
	yourAsmTotalTime = time.time() - timeStarted
	return (yourAsmTotalTime)

def printBanner():
	print(SALMON +"________________________________________________________________________________________________")
	print(CYAN + "      ___           ___           ___           ___           ___           ___           ___   ")
	print("     /  /\         /  /\         /  /\         /  /\         /__/\         /  /\         /  /\ ")
	print("    /  /:/        /  /::\       /  /::\       /  /:/_       _\_ \:\       /  /::\       /  /::\   ")
	print("   /  /:/        /  /:/\:\     /  /:/\:\     /  /:/ /\     /__/\ \:\     /  /:/\:\     /  /:/\:\ ")
	print("  /  /:/  ___   /  /:/  \:\   /  /:/-/:/    /  /:/ /:/_   _\_ \:\ \:\   /  /:/-/::\   /  /:/-/:/  ")
	print(" /__/:/  /  /\ /__/:/ \__\:\ /__/:/ /:/___ /__/:/ /:/ /\ /__/\ \:\ \:\ /__/:/ /:/\:\ /__/:/ /:/___")
	print(" \  \:\ /  /:/ \  \:\ /  /:/ \  \:\/:::::/ \  \:\/:/ /:/ \  \:\ \:\/:/ \  \:\/:/__\/ \  \:\/:::::/")
	print("  \  \:\  /:/   \  \:\  /:/   \  \::/----   \  \::/ /:/   \  \:\ \::/   \  \::/       \  \::/---- ")
	print("   \  \:\/:/     \  \:\/:/     \  \:\        \  \:\/:/     \  \:\/:/     \  \:\        \  \:\     ")
	print("    \  \::/       \  \::/       \  \:\        \  \::/       \  \::/       \  \:\        \  \:\ ")
	print("     \__\/         \__\/         \__\/         \__\/         \__\/         \__\/         \__\/   ")
	print(SALMON +"_________________________________________________________________________________________________" + EOC)
	print(WHITE + "                                                                           by altikka & atenhune" + EOC)

def main():
	printBanner()
	dir_path = "speed_files/"
	dir_cont = os.listdir(dir_path)
	dir_cont.sort()
	for file in dir_cont:
		if file == "asmall.s":
			print(YELLOW + "Testing with small file size:" + EOC)
			realTotalTime = 0
			yourTotalTime = 0
			s_file = "%s%s" % (dir_path, file)
			for i in range(20):
				realTotalTime += timeRealAsm(s_file)
				yourTotalTime += timeYourAsm(s_file)
			realTotalTime /= 20
			yourTotalTime /= 20
			result = '{:.1%}'.format(realTotalTime/yourTotalTime)
			if (realTotalTime/yourTotalTime) > 1:
				print("Speed: " + GREEN + str(result) + EOC)
			elif (realTotalTime/yourTotalTime) > 0.5:
				print("Speed: " + YELLOW + str(result) + EOC)
			else:
				print("Speed: " + RED + str(result) + EOC)
		if file == "bmedium.s":
			print(YELLOW + "Testing with medium file size:" + EOC)
			realTotalTime = 0
			yourTotalTime = 0
			s_file = "%s%s" % (dir_path, file)
			for i in range(20):
				realTotalTime += timeRealAsm(s_file)
				yourTotalTime += timeYourAsm(s_file)
			realTotalTime /= 20
			yourTotalTime /= 20
			result = '{:.1%}'.format(realTotalTime/yourTotalTime)
			if (realTotalTime/yourTotalTime) > 1:
				print("Speed: " + GREEN + str(result) + EOC)
			elif (realTotalTime/yourTotalTime) > 0.5:
				print("Speed: " + YELLOW + str(result) + EOC)
			else:
				print("Speed: " + RED + str(result) + EOC)
		if file == "clarge.s":
			print(YELLOW + "Testing with large file size:" + EOC)
			realTotalTime = 0
			yourTotalTime = 0
			s_file = "%s%s" % (dir_path, file)
			for i in range(20):
				realTotalTime += timeRealAsm(s_file)
				yourTotalTime += timeYourAsm(s_file)
			realTotalTime /= 20
			yourTotalTime /= 20
			result = '{:.1%}'.format(realTotalTime/yourTotalTime)
			if (realTotalTime/yourTotalTime) > 1:
				print("Speed: " + GREEN + str(result) + EOC)
			elif (realTotalTime/yourTotalTime) > 0.5:
				print("Speed: " + YELLOW + str(result) + EOC)
			else:
				print("Speed: " + RED + str(result) + EOC)
		if file == "dmassive.s":
			print(YELLOW + "Testing with massive file size:" + GRAY + ITALIC + "     This takes few minutes"+ EOC)
			realTotalTime = 0
			yourTotalTime = 0
			s_file = "%s%s" % (dir_path, file)
			for i in range(10):
				realTotalTime += timeRealAsm(s_file)
				yourTotalTime += timeYourAsm(s_file)
			realTotalTime /= 10
			yourTotalTime /= 10
			result = '{:.1%}'.format(realTotalTime/yourTotalTime)
			if (realTotalTime/yourTotalTime) > 1:
				print("Speed: " + GREEN + str(result) + EOC)
			elif (realTotalTime/yourTotalTime) > 0.5:
				print("Speed: " + YELLOW + str(result) + EOC)
			else:
				print("Speed: " + RED + str(result) + EOC)
	os.system("rm %s*.cor" % dir_path)

if __name__ == "__main__":
	main()