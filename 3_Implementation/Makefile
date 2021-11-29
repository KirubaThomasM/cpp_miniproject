PROJ_NAME = E_Library

BUILD_DIR = Build

# All Source code files
SRC =	src/item.cpp\
		src/book.cpp\
		src/journal.cpp\
		src/article.cpp\
		src/methods.cpp 
# All header file paths
INC = -I inc

ifdef OS
   RM = del 
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
      EXEC = out
   endif
endif
.PHONY: run clean test doc all

all:$(BUILD_DIR)
	g++ $(INC) $(SRC) main.cpp -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))
$(BUILD_DIR):
# Create directory to store the built files
	mkdir $(BUILD_DIR)
run:
	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))

cppcheck:
	cppcheck --enable=all $(SRC) main.cpp
debug:
	g++ $(INC) $(SRC) main.cpp -g -o $(PROJ_NAME).$(EXEC)
	gdb $(PROJ_NAME).$(EXEC)
doc:
# Build the code documentation using Doxygen command line utility
	make -C documentation
clean:
	$(RM) $(call FixPath,$(BUILD_DIR)\*)
	#make -C documentation clean
valgrind:
	valgrind ./3_Implementation/Build/E_Library.out

