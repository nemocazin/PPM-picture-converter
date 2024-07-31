#!/bin/bash

#
# @brief     File to install al the lib and necessaries to use the code
# 
# @author    CAZIN Némo
# @date      2024
# 

# Colors (ANSI)
BLUE='\033[0;34m'
CYAN='\033[0;36m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RESET='\033[0m'

#!* BEFORE INSTALL ####################################

# Create log directory if it doesn't exist
mkdir -p build
mkdir -p log
mkdir -p images

# Redirect stdout and stderr to log/log_install
exec > >(tee -a log/install.log) 2>&1




#!* UPDATE PACKAGES ##########################################
echo -e "${CYAN}Updating package lists..."
apt-get update
echo -e "${GREEN}Update done.${RESET}"
##############################################################




#!* INSTALL g++ ##############################################
echo -e "${CYAN}Installing gcc...${RESET}"
apt-get -y install gcc

# Verification of the install
if [ $? -eq 0 ]; then
    echo -e "${GREEN}g++ has been installed sucessfully.${RESET}"
else
    echo -e "${RED}g++ installation failed.${RESET}"
    exit 1
fi
##############################################################




#!* INSTALL MAKE #############################################
echo -e "${CYAN}Installing make...${RESET}"
apt-get -y install make

# Verification of the install
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Make has been installed sucessfully.${RESET}"
else
    echo -e "${RED}Make installation failed.${RESET}"
    exit 1
fi
##############################################################




#!* INSTALL BUILD ESSENTIAL ##################################
echo -e "${CYAN}Installing build-essential...${RESET}"
apt-get -y install build-essential

# Verification of the install
if [ $? -eq 0 ]; then
    echo -e "${GREEN}build-essential has been installed sucessfully.${RESET}"
else
    echo -e "${RED}build-essential installation failed.${RESET}"
    exit 1
fi
##############################################################




#!* INSTALL CHECK LIBRARY ####################################

# Install check library
echo -e "${CYAN}Installing check library...${RESET}"
apt-get install -y check

# Verification of the install
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Check lib has been installed sucessfully.${RESET}"
else
    echo -e "${RED}Check lib installation failed.${RESET}"
    exit 1
fi
##############################################################



#!* INSTALL GCOV COVERAGE LIBRARY ############################

# Install the coverage library
echo -e "${CYAN}Installing gcov coverage library...${RESET}"
apt-get install -y gcc

# Verification of the install
if [ $? -eq 0 ]; then
    echo -e "${GREEN}gcov coverage lib has been installed sucessfully.${RESET}"
else
    echo -e "${RED}gcov coverage lib installation failed.${RESET}"
    exit 1
fi
##############################################################




#!* INSTALL LCOV COVERAGE EXTENSION ##########################

# Install the coverage extension
echo -e "${CYAN}Installing lcov coverage extension...${RESET}"
apt-get install -y lcov

# Verification of the extension
if [ $? -eq 0 ]; then
    echo -e "${GREEN}lcov coverage extension has been installed sucessfully.${RESET}"
else
    echo -e "${RED}lcov coverage extension installation failed.${RESET}"
    exit 1
fi
##############################################################




#!* INSTALL XDG ##############################################
echo -e "${CYAN}Installing xdg-utils...${RESET}"
apt-get -y install xdg-utils

# Verification of the install
if [ $? -eq 0 ]; then
    echo -e "${GREEN}xdg-utils has been installed sucessfully.${RESET}"
else
    echo -e "${RED}xdg-utils installation failed.${RESET}"
    exit 1
fi
##############################################################



echo -e "${BLUE}Installation script completed.${RESET}"