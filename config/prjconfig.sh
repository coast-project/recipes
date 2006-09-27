###########################################################################
# Copyright (c) 1999-2000 itopia
# All Rights Reserved
#
# $Id$
#
# project specific variables and directories, loaded from within config.sh
#
############################################################################

############################################################################
#
# In this ection you should only adjust but NOT remove any of the given variables
# because these are used from within other scripts
#

# overwrite this one ONLY if the LOGDIR variable points to the wrong place
#LOGDIR=log

SERVERNAME="recipes"
PRJ_DESCRIPTION="Step by step instructions to WebDisplay2"
#PID_FILE=$PROJECTDIR/$LOGDIR/$SERVERNAME.PID

# name of the tared and gzipped distribution file, caution: try to use short names
# because some CD burning software do only store 8.3 names
#TARGZNAME=$SERVERNAME.tgz

# specify ALL of your filterable configurations, to build for a specific configuration
# you have to specify ONE on the command line in case of a doall.sh execution
SWITCHGROUPS="DevTest Prod TestCases|itopia foolabs tkf"
SWITCHRULE="DevTest"		# default rule

# overwrite this one ONLY if the WD_PATH variable points to the wrong place
#WD_PATH=config

# use this function to do preparations prior to creating the distribution package
# e.g. increment a build number
#function preDoallFunc {}

############################################################################
#
# from here on you can add your own variables which you can use in the
# project specific prjcopy.sh file for example
