CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC_DIR = 2024
UTILS_DIR = utils
BUILD_DIR = build

UTILS_SRC = $(UTILS_DIR)/utils.cpp
UTILS_OBJ = $(BUILD_DIR)/utils.o

DAYS = day1

TARGETS = $(patsubst %, $(BUILD_DIR)/%, $(DAYS))

all: $(TARGETS)

$(UTILS_OBJ): $(UTILS_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compiler chaque jour
$(BUILD_DIR)/%: $(SRC_DIR)/%/main.cpp $(UTILS_OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< $(UTILS_OBJ) -o $@

# Nettoyage des fichiers générés
clean:
	rm -rf $(BUILD_DIR)