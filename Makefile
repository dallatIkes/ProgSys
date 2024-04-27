.PHONY : newTP

newTP:
	@echo "Création du répertoire $(TP)"
	@mkdir $(TP)
	@echo "Création des sous-répertoires src bin et doc"
	@mkdir $(TP)/src $(TP)/src/include $(TP)/bin $(TP)/doc
	@echo "Création du fichier Markdown"
	@touch $(TP)/doc/notes.md
	@echo "Création du fichier Makefile"
	@touch $(TP)/Makefile
