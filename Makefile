PROJECT_DIR := --project-directory .
COMPOSE_DIR := docker/compose

.PHONY: jetson-build jetson-up jetson-down jetson-restart jetson-rebuild jetson-logs laptop-build laptop-up laptop-down laptop-restart

jetson-build:
	docker build -t robot_edge_stack_base:humble -f docker/jetson/Dockerfile.base .
	docker build -t robot_edge_stack_discovery:humble -f docker/jetson/Dockerfile.discovery .
	docker build -t robot_edge_stack_camera:humble -f docker/jetson/Dockerfile.cam .

jetson-up:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/robot.compose.yaml up -d

jetson-down:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/robot.compose.yaml down

jetson-restart:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/robot.compose.yaml restart $(s)

jetson-rebuild:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/robot.compose.yaml up -d --build $(s)

jetson-logs:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/robot.compose.yaml logs -f $(s)

laptop-build:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/dev.compose.yaml build --no-cache

laptop-up:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/dev.compose.yaml up

laptop-down:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/dev.compose.yaml down

laptop-restart:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/dev.compose.yaml restart $(s)

laptop-logs:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/dev.compose.yaml logs -f $(s)
