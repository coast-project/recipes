#!/bin/ksh 
# batch file to start cookbook service

export WWW_DIR=$DEV_HOME/WWW
export COAST_ROOT=$WWW_DIR/recipes
export COAST_PATH=.:config:config/HTMLTemplates

$WWW_DIR/wdapp/wdapp AppId=recipes
