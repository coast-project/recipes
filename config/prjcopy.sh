###########################################################################
# Copyright (c) 1999-2000 itopia
# All Rights Reserved
#
# $Id$
#
# project specific copying and setting of permissions for directories
# loaded from within cpall.sh
#
# check the file config.sh to have an overview of the predefined variables
# you can use for defined directories etc
#
############################################################################

# NOTE: $TMPDIR/bin already created and generic parts copied (wdserver, wdapp)
# NOTE: $TMPDIR/${CONFIGDIR:-config} already created and generic parts copied (any, sh)
# NOTE: $TMPDIR/lib already created and generic parts copied (so)
# NOTE: $TMPDIR/scripts already created and generic parts copied (sh, awk)

# NOTE: try not to use recursive copying because of possible CVS directories

# NOTE: please adjust permissions of directories for security reason

# you can modify the following parts, these are here as example

mkdir -p $TMPDIR/${CONFIGDIR:-config}/HTMLTemplates/static/images
mkdir -p $TMPDIR/${CONFIGDIR:-config}/HTMLTemplates/static/applets
mkdir -p $TMPDIR/${CONFIGDIR:-config}/HTMLTemplates/static/styles
mkdir -p $TMPDIR/${LOGDIR}/rotate

# copy everything now
cp -p ${PROJECTDIRABS}/SomeData.any $TMPDIR
cp -p $CONFIGDIRABS/HTMLTemplates/*.html $TMPDIR/${CONFIGDIR:-config}/HTMLTemplates
cp -p $CONFIGDIRABS/HTMLTemplates/static/images/*.gif  $TMPDIR/${CONFIGDIR:-config}/HTMLTemplates/static/images
cp -p $CONFIGDIRABS/HTMLTemplates/static/images/*.jpeg  $TMPDIR/${CONFIGDIR:-config}/HTMLTemplates/static/images
cp -p $CONFIGDIRABS/HTMLTemplates/static/applets/*.class  $TMPDIR/${CONFIGDIR:-config}/HTMLTemplates/static/applets
cp -p $CONFIGDIRABS/HTMLTemplates/static/styles/Formats.css  $TMPDIR/${CONFIGDIR:-config}/HTMLTemplates/static/styles
cp -p $CONFIGDIRABS/recipes_cert.pem $TMPDIR/${CONFIGDIR:-config}
cp -p $CONFIGDIRABS/recipes_key.pem $TMPDIR/${CONFIGDIR:-config}

chmod 664 $TMPDIR/${CONFIGDIR:-config}/HTMLTemplates/*.html
chmod 444 $TMPDIR/${CONFIGDIR:-config}/HTMLTemplates/static/images/*gif
chmod 444 $TMPDIR/${CONFIGDIR:-config}/HTMLTemplates/static/images/*jpeg
chmod 440 $TMPDIR/${CONFIGDIR:-config}/*.pem
