PROJECT_DIR := --project-directory .
COMPOSE_DIR := docker/compose

.PHONY: jetson-build jetson-up jetson-down jetson-logs laptop-build laptop-up laptop-down

jetson-build:
	docker build -t robot_edge_stack_base:humble -f docker/jetson/Dockerfile.base .
	docker build -t robot_edge_stack_discovery:humble -f docker/jetson/Dockerfile.discovery .
	docker build -t robot_edge_stack_camera:humble -f docker/jetson/Dockerfile.cam .

jetson-up:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/robot.compose.yaml up -d

jetson-down:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/robot.compose.yaml down

jetson-logs:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/robot.compose.yaml logs -f $(s)

laptop-build:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/dev.compose.yaml build --no-cache

laptop-up:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/dev.compose.yaml up

laptop-down:
	docker compose $(PROJECT_DIR) -f $(COMPOSE_DIR)/dev.compose.yaml down
