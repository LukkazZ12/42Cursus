WVENV_NAME=core

# Define Colors
RESET=\033[0m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m

all:
	@echo Hello

run:
	@uvicorn game_project.asgi:application --host 0.0.0.0 --port 8081 --reload

$(VENV_NAME):
	@echo -e "$(BLUE)🔨 Building VENV: [$(VENV_NAME)]...$(RESET)"
	@python3 -m venv $(VENV_NAME)
	@echo -e "$(GREEN)✅ VENV: [$(VENV_NAME)] built successfully!$(RESET)"
	@echo -e "$(YELLOW)📦 Installing dependencies into VENV: [$(VENV_NAME)]...$(RESET)"
	@bash -c 'source ./$(VENV_NAME)/bin/activate && pip install -r requirements.txt > /dev/null' \
		&& echo -e "$(GREEN)✅ Dependencies installed into VENV: [$(VENV_NAME)]!$(RESET)" \
		|| echo -e "$(RED)❌ Error: Failed to install dependencies into VENV: [$(VENV_NAME)]!$(RESET)"

build: $(VENV_NAME)

migrate:
	@bash -c 'python manage.py makemigrations'
	@bash -c 'python manage.py migrate'

clean:

fclean:
	@rm -rf core
