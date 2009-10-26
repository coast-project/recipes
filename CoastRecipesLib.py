import os, pdb
import StanfordUtils
from stat import *

packagename = StanfordUtils.getPackageName(__name__)

def setUp(target, source, env):
    logpath = env['BASEOUTDIR'].Dir(os.path.join('tests', packagename, 'log', 'rotate'))
    path = env['BASEOUTDIR'].Dir(os.path.join('tests', packagename)).Dir('config')
    if not os.path.isdir(logpath.abspath):
        os.makedirs(logpath.abspath)

def tearDown(target, source, env):
    pass

buildSettings = {
    packagename : {
        'includeSubdir'    : 'recipes_src',
        'linkDependencies' : ['CoastWDBase'],
        'sourceFiles'      : StanfordUtils.listFiles(['recipes_src/*.cpp']),
        'targetType'       : 'LibraryShared',
        'appendUnique'     : { 'CPPDEFINES' : [packagename.upper() + '_IMPL'] },
        'public' : {
            'includeSubdir': 'recipes_src',
            'includes'     : StanfordUtils.listFiles(['recipes_src/*.h']),
        }
    },
    'Runner' : {
        'targetType'       : 'AppTest',
        'requires'         : [packagename + '.' + packagename, 'CoastActions', 'CoastRenderers', 'CoastStdDataAccess', 'CoastAppLog'],
        'usedTarget'       : 'wdapp.wdapp',
        'copyFiles'        : [(StanfordUtils.findFiles(['.', 'config'],['.txt', '.html', '.any', '.pem', '.gif', '.png', '.jpg', '.jpeg']), S_IRUSR|S_IRGRP|S_IROTH)],
        'runConfig'        : {
            'setUp': setUp,
            'tearDown': tearDown,
        },
    },
}

StanfordUtils.createTargets(packagename, buildSettings)
