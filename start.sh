#!/bin/ksh 
# batch file to start cookbook service

export WWW_DIR=$DEV_HOME/WWW
export WD_ROOT=$WWW_DIR/recipes
export WD_PATH=.:config:config/HTMLTemplates

$WWW_DIR/wdapp/wdapp AppId=recipes
