.ONESHELL:
SHELL := /bin/bash
.DEFAULT_GOAL := help

.PHONY: help
.DEFAULT_GOAL := help
help:
	@grep -h -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: create-local
create-local: ## Create SyE local directory
ifeq (,$(wildcard $(HOME)/.sye))
	@mkdir -p $(HOME)/.sye
endif
ifeq (,$(wildcard $(HOME)/.sye/config))
	@mkdir -p $(HOME)/.sye/config
endif
ifeq (,$(wildcard $(HOME)/.sye/theme))
	@mkdir -p $(HOME)/.sye/config
endif

.PHONY: clone-config
clone-config: ## Clone SyE config directory
	@cp -r ./samples/config/config.yaml $(HOME)/.sye/config

.PHONY: clone-theme
clone-theme: ## Clone SyE theme directory
	@cp -r ./samples/theme/* $(HOME)/.sye/theme

.PHONY: prepare
prepare: ## Install prerequisites
ifeq (,$(wildcard $(shell pwd)/build))
	@mkdir $(shell pwd)/build
endif

.PHONY: build
build: prepare create-local clone-config clone-theme ## Build the project
	@cd $(shell pwd)/build && cmake .. && make

.PHONY: install
install: ## Install built executables to the system directory
	@cd $(shell pwd)/build && make install