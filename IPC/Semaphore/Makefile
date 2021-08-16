###############################################################################
# Copyrights(c) 2019.    Jielong Lin (JLLim).   All rights reserved.
#     jielong.lin@qq.com, 2019-08-19                             
#
# Created by JLLim @2019-08-19 v0:
#     Support for project basic architect definition          
###########################################################################
all :

MKRootPath=$(strip $(shell pwd))

#-----------------------------------------------------------------------------------------------
# Configuration 
#-----------------------------------------------------------------------------------------------

MODULE_A_LIBS := libAPI.a

MODULE_SO_LIBS := libAPI.so

MODULE_EXECS := app

MODULE_INCS := inc/wordprocess.h


MODULE_A_LIBS_src := $(shell find $(MKRootPath)/src -type f -a -name *.c)
MODULE_SO_LIBS_src := $(shell find $(MKRootPath)/src -type f -a -name *.c)
MODULE_EXECS_src := $(shell find $(MKRootPath)/demo -type f -a -name *.c)


COMM_FLAGS := -I"$(MKRootPath)" -I"$(MKRootPath)/inc" -I. -g  -fPIC
#COMM_FLAGS += -lpthread

LIB_SO_FLAGS := $(COMM_FLAGS) -shared

LIB_A_FLAGS := $(COMM_FLAGS)

EXEC_FLAGS := $(COMM_FLAGS)
EXEC_FLAGS += -L"$(MKRootPath)/out/static_libs/dir.libAPI.a"
EXEC_FLAGS += -L"$(MKRootPath)/out/shared_libs/dir.libAPI.so"
EXEC_FLAGS += -l"API"


libAPI.a : $(MODULE_A_LIBS_src)
	@$(call FN_static_lib_create)

libAPI.so : $(MODULE_SO_LIBS_src)
	@$(call FN_shared_lib_create)

app : $(MODULE_EXECS_src)
	@$(call FN_exec_create)


#-----------------------------------------------------------------------------------------------
# Please not modify it
#     Not compile then link to exec or lib, it only pack head files, exec, lib to sdk directory
#-----------------------------------------------------------------------------------------------
sdk : $(MODULE_A_LIBS) $(MODULE_SO_LIBS) $(MODULE_EXECS)   \
      $(shell [ ! -e "$(MKRootPath)/sdk" ]                  \
               && mkdir -p $(MKRootPath)/sdk)               \
      $(shell [ ! -e "$(MKRootPath)/sdk/usr/include" ]      \
               && mkdir -p $(MKRootPath)/sdk/usr/include)   \
      $(shell [ ! -e "$(MKRootPath)/sdk/usr/lib" ]          \
               && mkdir -p $(MKRootPath)/sdk/usr/lib)       \
      $(shell [ ! -e "$(MKRootPath)/sdk/usr/bin" ]          \
               && mkdir -p $(MKRootPath)/sdk/usr/bin)
	@$(call FN_sdk_usr_lib_packing, $(MODULE_SO_LIBS))
	@$(call FN_sdk_usr_lib_packing, $(MODULE_A_LIBS))
	@$(call FN_sdk_usr_bin_packing, $(MODULE_EXECS))
	@$(call FN_sdk_usr_include_packing, $(MODULE_INCS))

#-----------------------------------------------------------------------------------------------
# Please not modify it which is the standardized build system 
#-----------------------------------------------------------------------------------------------
.PHONY : clean  sdk  all
all : sdk                                                     \
      $(shell [ ! -e "$(MKRootPath)/out" ]                  \
               && mkdir -p $(MKRootPath)/out)               \
      $(shell [ ! -e "$(MKRootPath)/out/static_libs" ]      \
               && mkdir -p $(MKRootPath)/out/static_libs)   \
      $(shell [ ! -e "$(MKRootPath)/out/shared_libs" ]      \
               && mkdir -p $(MKRootPath)/out/shared_libs)   \
      $(shell [ ! -e "$(MKRootPath)/out/execs" ]            \
               && mkdir -p $(MKRootPath)/out/execs)
	@[ x"`which tree`" != x ] && tree -h

clean :
	@[ -e "$(MKRootPath)/out" ] && rm -rvf $(MKRootPath)/out
	@[ -e "$(MKRootPath)/sdk" ] && rm -rvf $(MKRootPath)/sdk

#-----------------------------------------------------------------------------------------------
# Function Utilities 
#-----------------------------------------------------------------------------------------------

#Usage:
#    $(call FN_static_lib_create)
#
define FN_static_lib_create
    [ ! -e $(MKRootPath)/out/static_libs/dir.$@ ] \
        && mkdir -pv $(MKRootPath)/out/static_libs/dir.$@; \
    cd $(MKRootPath)/out/static_libs/dir.$@; \
	$(CC) -c $^ $(LIB_A_FLAGS); \
	ar rcs $@ *.o; \
	cd - >/dev/null;
endef

#Usage:
#    $(call FN_shared_lib_create)
#
define FN_shared_lib_create
    [ ! -e $(MKRootPath)/out/shared_libs/dir.$@ ] && \
        mkdir -pv $(MKRootPath)/out/shared_libs/dir.$@; \
    cd $(MKRootPath)/out/shared_libs/dir.$@; \
	$(CC) -o $@ $^ $(LIB_SO_FLAGS); \
	cd - >/dev/null;
endef

#Usage:
#    $(call FN_exec_create)
#
define FN_exec_create
    [ ! -e $(MKRootPath)/out/execs/dir.$@ ] && mkdir -pv $(MKRootPath)/out/execs/dir.$@; \
    cd $(MKRootPath)/out/execs/dir.$@; \
	$(CC) -o $@ $^ $(EXEC_FLAGS); \
	cd - >/dev/null;
endef


#Usage:
#    $(call FN_sdk_usr_lib_packing, $(MODULE_A_LIBS))
#    $(call FN_sdk_usr_lib_packing, $(MODULE_SO_LIBS))
#
define FN_sdk_usr_lib_packing
	for fl in $(foreach _fl, $(shell echo $(1)), $(_fl)); \
	do \
		_sf_=`find $(MKRootPath)/out -type f -a -name $${fl} 2>/dev/null`; \
		if [ x"$${_sf_}" != x -a -e "$${_sf_}" ]; then               \
			if [ -e "$(MKRootPath)/sdk/usr/lib/$${fl}" ]; then        \
				rm -rf $(MKRootPath)/sdk/usr/lib/$${fl};              \
			fi;                                                          \
			cp -rf $${_sf_} $(MKRootPath)/sdk/usr/lib;                \
			echo "[SDK.USR.LIB.OK] $${_sf_} for $${fl}";                \
		else                                                             \
			echo "[SDK.USR.LIB.ERROR] Not found $${_sf_} for $${fl}";   \
			break;                                                       \
		fi;                                                              \
	done;
endef


#Usage:
#    $(call FN_sdk_usr_bin_packing, $(MODULE_EXECS))
#
define FN_sdk_usr_bin_packing
	for fl in $(foreach _fl, $(shell echo $(1)), $(_fl)); \
	do \
		_sf_=`find $(MKRootPath)/out -type f -a -name $${fl} 2>/dev/null`; \
		if [ x"$${_sf_}" != x -a -e "$${_sf_}" ]; then               \
			if [ -e "$(MKRootPath)/sdk/usr/bin/$${fl}" ]; then        \
				rm -rf $(MKRootPath)/sdk/usr/bin/$${fl};              \
			fi;                                                          \
			cp -rf $${_sf_} $(MKRootPath)/sdk/usr/bin;                \
			echo "[SDK.USR.BIN.OK] $${_sf_} for $${fl}";                \
		else                                                             \
			echo "[SDK.USR.BIN.ERROR] Not found $${_sf_} for $${fl}";   \
			break;                                                       \
		fi;                                                              \
	done;
endef

#Usage:
#    $(call FN_sdk_usr_include_packing, $(MODULE_INCS))
#
define FN_sdk_usr_include_packing
	for fl in $(foreach _fl, $(shell echo $(1)), $(_fl)); \
	do \
		_sf_=`find $(MKRootPath) -type f | grep "$${fl}" 2>/dev/null`; \
		if [ x"$${_sf_}" != x -a -e "$${_sf_}" ]; then               \
			if [ -e "$(MKRootPath)/sdk/usr/include/$${fl}" ]; then        \
				rm -rf $(MKRootPath)/sdk/usr/include/$${fl};              \
			fi;                                                          \
			cd 	$(MKRootPath);  \
			cp --parents -rf $${fl} $(MKRootPath)/sdk/usr/include;        \
			echo "[SDK.USR.INC.OK] $${_sf_} for $${fl}";                \
		else                                                             \
			echo "[SDK.USR.INC.ERROR] Not found $${_sf_} for $${fl}";   \
			break;                                                       \
		fi;                                                              \
	done;
endef



