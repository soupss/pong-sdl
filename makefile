INC_DIR := inc
SRC_DIR := src
OBJ_DIR := obj

OUT	:= main
CC       := g++
CPPFLAGS := -I $(INC_DIR) -MMD -MP
CXXFLAGS := -Wall
LDFLAGS  :=
LDLIBS   := -lSDL2 -lSDL2_image

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS    := $(wildcard $(OBJ_DIR)/*.d)

$(OUT): $(OBJECTS)
	@$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJECTS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(OUTPUT_OPTION) $<

clean:
	$(RM) $(DEPS) $(OBJECTS) $(OUT)
