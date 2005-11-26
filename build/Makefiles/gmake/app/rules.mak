# -*- makefile -*- Time-stamp: <05/03/28 23:44:09 ptr>
# $Id$

dbg-shared:	$(OUTPUT_DIR_DBG) ${PRG_DBG}
stldbg-shared:	$(OUTPUT_DIR_STLDBG) ${PRG_STLDBG}
release-shared:	$(OUTPUT_DIR) ${PRG}

dbg-static:	$(OUTPUT_DIR_A_DBG) ${PRG_A_DBG}
stldbg-static:	$(OUTPUT_DIR_A_STLDBG) ${PRG_A_STLDBG}
release-static:	$(OUTPUT_DIR_A) ${PRG_A}

${PRG}:	$(OBJ) $(LIBSDEP)
ifneq (bcc, $(COMPILER_NAME))
	$(LINK.cc) $(LINK_OUTPUT_OPTION) ${START_OBJ} $(OBJ) $(LDLIBS) ${STDLIBS} ${END_OBJ}
else
	$(subst /,\,$(LINK.cc) $(START_OBJ) $(OBJ) $(END_OBJ),$(LINK_OUTPUT_OPTION),,$(LDLIBS) $(STDLIBS),,)
endif

${PRG_DBG}:	$(OBJ_DBG) $(LIBSDEP)
ifneq (bcc, $(COMPILER_NAME))
	$(LINK.cc) $(LINK_OUTPUT_OPTION) ${START_OBJ} $(OBJ_DBG) $(LDLIBS) ${STDLIBS} ${END_OBJ}
else
	$(subst /,\,$(LINK.cc) $(START_OBJ) $(OBJ_DBG) $(END_OBJ),$(LINK_OUTPUT_OPTION),,$(LDLIBS) $(STDLIBS),,)
endif

${PRG_STLDBG}:	$(OBJ_STLDBG) $(LIBSDEP)
ifneq (bcc, $(COMPILER_NAME))
	$(LINK.cc) $(LINK_OUTPUT_OPTION) ${START_OBJ} $(OBJ_STLDBG) $(LDLIBS) ${STDLIBS} ${END_OBJ}
else
	$(subst /,\,$(LINK.cc) $(START_OBJ) $(OBJ_STLDBG) $(END_OBJ),$(LINK_OUTPUT_OPTION),,$(LDLIBS) $(STDLIBS),,)
endif

${PRG_A_DBG}:	$(OBJ_A_DBG) $(LIBSDEP)
	$(LINK.cc) $(LINK_OUTPUT_OPTION) ${START_OBJ} $(OBJ_A_DBG) $(LDLIBS) ${STDLIBS} ${END_OBJ}

${PRG_A_STLDBG}:	$(OBJ_A_STLDBG) $(LIBSDEP)
	$(LINK.cc) $(LINK_OUTPUT_OPTION) ${START_OBJ} $(OBJ_A_STLDBG) $(LDLIBS) ${STDLIBS} ${END_OBJ}

${PRG_A}:	$(OBJ_A) $(LIBSDEP)
	$(LINK.cc) $(LINK_OUTPUT_OPTION) ${START_OBJ} $(OBJ_A) $(LDLIBS) ${STDLIBS} ${END_OBJ}

