INC_DIR := inc
SRC_DIR := src
OBJ_DIR := obj
BIN := main

all:     CPPFLAGS := -I $(INC_DIR) -MMD -MP
all:     CXXFLAGS := -Wall -Wpedantic -g -std=c++17
all:     LDFLAGS  :=
all:     LDLIBS   := -lSDL2 -lSDL2_image -lSDL2_ttf
all:	 BIN_DIR  := bin/debug
all:     $(BIN)

release: CPPFLAGS := -I $(INC_DIR) -MMD -MP
release: CXXFLAGS := -Wall -Wpedantic -Ofast
release: LDFLAGS  :=
release: LDLIBS   := -lSDL2 -lSDL2_image -lSDL2_ttf
release: BIN_DIR  := bin/release
release: $(BIN)

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS    := $(wildcard $(OBJ_DIR)/*.d)

$(BIN): $(OBJS)
	@$(CXX) $(LDFLAGS) $(LDLIBS) $^ -o $(BIN_DIR)/$@

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(OUTPUT_OPTION) $<

clean:
	-@$(RM) $(OBJ_DIR)/* bin/debug/$(BIN) bin/release/$(BIN)
