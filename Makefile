#
# @brief     Makefile
# 
# @author    CAZIN Némo
# @date      2024
# 

# Compiling Flags
CC = gcc 
CFLAGS = -Wall
EXTRA_CFLAGS 	= -fprofile-arcs -ftest-coverage
EXTRA_LDFLAGS 	= --coverage 

# Directories & files
SRCDIR 			= src/
BUILDDIR 		= build/
LOGDIR 			= log/
TARGET			= $(BUILDDIR)main
LOGFILE			= $(LOGDIR)make.log

# Colors (ANSI)
BLUE	:= \033[0;34m
CYAN	:= \033[0;36m
RED 	:= \033[0;31m
GREEN 	:= \033[0;32m
YELLOW 	:= \033[0;33m
RESET 	:= \033[0m

### Redirect all output to log file
MAKEFLAGS += --silent

#### Unitary tests variables 
TEST_DIR 			= tests/src
TEST_MAIN 			= tests/main.c
TEST_EXEC 			= build/test
TEST_LDFLAGS 		= -lcheck -lpthread -lm -lrt -lsubunit



all : | $(LOG_FILE) 
	@$(MAKE) build 2>&1 | tee -a $(LOGFILE)

####################### BUILDING FILES ########################
build: $(BUILDDIR)inout.o $(BUILDDIR)convert.o $(BUILDDIR)main.o
	@echo "$(CYAN)[LOG] Compiling c files...$(RESET)"
	$(CC) $(CFLAGS)  $^ -o $(TARGET)
	@echo "$(BLUE)[LOG] Compiling done.$(RESET)"

$(BUILDDIR)inout.o: $(SRCDIR)inout.c
	$(CC) $(CFLAGS) -c $< -o $@ 
	
$(BUILDDIR)convert.o: $(SRCDIR)convert.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(BUILDDIR)main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@ 
###############################################################



########################## Cleaning ###########################
clean :
	@echo "$(CYAN)[LOG] Cleaning builded files...$(RESET)"
	rm -rf $(BUILDDIR)* 
	@echo "$(CYAN)[LOG] Cleaning logs...$(RESET)"
	rm -rf $(LOGDIR)*
	@echo "$(GREEN)[LOG] Cleaning done.$(RESET)"
###############################################################

.PHONY: all build clean