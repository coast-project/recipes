#
# Standard Java Project Makefile

# ------------------------------------------------------------------------------
# Including the generated make support files
#
#     Include the file 'macros.incl'
#     which defines all project dependent SNIFF_* macros.
include .sniffdir/macros.incl
#
# ------------------------------------------------------------------------------
# The SNIFF_* macros are defined in the Make View of the Project Attributes
#
# Java Html Target
JAVA_HTML_TARGET 		= $(SNIFF_JAVA_HTML_TARGET)
JAVA_APPLET_CLASSES 	= $(SNIFF_JAVA_APPLET_CLASSES)
#
# Java Application Target
JAVA_APPLICATION_TARGET	= $(SNIFF_JAVA_APPLICATION_TARGET)
JAVA_TARGET_CLASSES		= $(SNIFF_JAVA_TARGET_CLASSES)
#
# Java Jar Target
JAVA_JAR_TARGET			= $(SNIFF_JAVA_JAR_TARGET)
#
# Java Jar Additional Files
#SNIFF_JAVA_JAR_FILES	= <your files you want to add to the JAR file, whitespaces are allowed like *.gif>
#
# Java native interface support activation
#JNI_SUPPORT = 1
#
# Java RMI support activation
#RMI_SUPPORT = 1
#
# Java RMI Files
#SNIFF_JAVA_RMI_FILES	= <your Java RMI files>
#
# Java IDL support activation
# IDLJ_SUPPORT = 1
#
#     Recursive make directories
SUBDIRS           = $(SNIFF_SUBDIRS)
#
# PRE_TARGETS is currently used only for IDL make support. 
#     The PRE_TARGETS macro is needed, since it is not possible to create a
#     simple implicit rule to compile the IDL files
#PRE_TARGETS     = $(SNIFF_PRE_TARGETS)
#
include $(SNIFF_DIR)/make_support/general.java.mk
#include $(SNIFF_DIR)/make_support/general.javapure.mk (without sniffjmake)
#
# Include the generated Make Support File 'dependencies.incl'.
include $(SNIFF_MAKEDIR)/$(SNIFF_DEPEND_INCL)
#
########## Customizing ##########
#
#        Java compiler
#JAVAC = javac
#ALL_JFLAGS = -g
#
#
#        Java native code generator
#JAVAH = javah
#ALL_JNIFLAGS =
#
#
#        Java RMI compiler
#RMIC = rmic
#ALL_RMIFLAGS = -g
#
#
#        OrbixWeb IDL to Java compiler
#IDLJ = idlj
#ALL_IDLJFLAGS = -jO
#
#
#        Java archive
#JAR = jar
#ALL_JARFLAGS = -cvOf
#
#
#        Java interpreter
#JAVA_INTERPRETER = java
#
#
#        Java applet viewer
#JAVA_APPLET_VIEWER = appletviewer
#
