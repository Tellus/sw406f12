.PHONY: clean All

All:
	@echo ----------Building project:[ Main - Debug ]----------
	@"$(MAKE)" -f "Main.mk"
clean:
	@echo ----------Cleaning project:[ Main - Debug ]----------
	@"$(MAKE)" -f "Main.mk" clean
