# Name of the project
PROJECT_NAME=stack

TEST_NAME= Test_$(PROJECT_NAME)

#Environment variable
CC= gcc

CFLAGS= -o

# Output directory
BUILD= build


# All source code files
SRC= src/createstack.c\
src/deletestack.c\
src/push.c\
src/pop.c\
src/peek.c


# All test source files
TEST=test/test_stack.c\
unity/unity.c

# All include folders with header files
INC=-I inc\
-I unity

ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      CPPCHECK=cppcheck $(SRC)	
	  VALGRIND=valgrind ./$(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC))
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif


# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test doc all

all: $(BUILD)
	$(CPPCHECK)
	$(CC) main.c $(SRC) $(INC) $(CFLAGS) $(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC))
	$(VALGRIND)

# Call `make run` to run the application
run:all
	./$(call FixPath,$(BUILD)/$(PROJECT_NAME).$(EXEC))

# Build and run the unit tests
test:$(SRC) $(TEST)
	gcc $^ $(INC) $(CFLAGS) $(call FixPath,$(BUILD)/$(TEST_NAME).$(EXEC))
	./$(call FixPath,$(BUILD)/$(TEST_NAME).$(EXEC))	

coverage:$(BUILD)
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 $(SRC) $(TEST) $(INC) $(CFLAGS) $(call FixPath,$(BUILD)/$(TEST_NAME).$(EXEC))
	./$(call FixPath,$(BUILD)/$(TEST_NAME).$(EXEC))

# Remove all the built files, invoke by `make clean`
clean:
	$(RM) $(call FixPath,$(BUILD)/*)
	$(RM) *.gcda *.gcno
	rmdir $(BUILD)

# Create new build folder if not present
$(BUILD):
	mkdir $(BUILD)	
