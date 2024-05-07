.PHONY : newTP

newTP:
	@echo "=== Création du répertoire $(TP)"
	@mkdir $(TP)

	@echo "=== Création des sous-répertoires src bin et doc"
	@mkdir $(TP)/src $(TP)/bin $(TP)/doc/

	@echo "=== Création du fichier Markdown"
	@touch $(TP)/doc/notes.md

	@echo "=== Création du fichier Makefile"
	@cp ./utils/TP_Makefile $(TP)/Makefile

	@echo "=== Création du fichier .gitignore"
	@touch $(TP)/doc/.gitignore
	@echo "*.pdf" > $(TP)/doc/.gitignore
