.ONESHELL:
SHELL := /bin/bash
.DEFAULT_GOAL := help

.PHONY: help
.DEFAULT_GOAL := help
help:
	@grep -h -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: create-local
create-local: ## Create SyE local directory
	@mkdir -p $(HOME)/.sye/config
	@mkdir -p $(HOME)/.sye/themes
	@mkdir -p $(HOME)/.sye/swap

.PHONY: clone-config
clone-config: ## Clone SyE config directory
ifeq (,$(wildcard $(HOME)/.sye/themes))
	@cp -r ./samples/config/config.yaml $(HOME)/.sye/config
endif
	
.PHONY: clone-theme
clone-theme: ## Clone SyE theme directory
	@cp -r ./samples/themes/* $(HOME)/.sye/themes/

.PHONY: prepare
prepare: ## Install prerequisites
	@mkdir -p $(shell pwd)/build

.PHONY: build
build: prepare create-local clone-config clone-theme ## Build the project
	@cd $(shell pwd)/build && cmake .. && make

.PHONY: install
install: ## Install built executables to the system directory
	@cd $(shell pwd)/build && make install