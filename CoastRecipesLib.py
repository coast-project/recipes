import os, pdb
import SConsider
from stat import *

packagename = SConsider.getPackageName(__name__)

def setUp(target, source, env):
    logpath = env['BASEOUTDIR'].Dir(os.path.join('tests', packagename, 'logs', 'rotate'))
    path = env['BASEOUTDIR'].Dir(os.path.join('tests', packagename)).Dir('config')
    if not os.path.isdir(logpath.abspath):
        os.makedirs(logpath.abspath)

def tearDown(target, source, env):
    pass

buildSettings = {
    packagename : {
        'includeSubdir'    : 'recipes_src',
        'linkDependencies' : ['CoastWDBase'],
        'sourceFiles'      : SConsider.listFiles(['recipes_src/*.cpp']),
        'targetType'       : 'LibraryShared',
        'appendUnique'     : { 'CPPDEFINES' : [packagename.upper() + '_IMPL'] },
        'public' : {
            'includeSubdir': 'recipes_src',
            'includes'     : SConsider.listFiles(['recipes_src/*.h']),
        }
    },
    'Runner' : {
        'targetType'       : 'AppTest',
        'requires'         : [packagename + '.' + packagename, 'CoastActions', 'CoastRenderers', 'CoastStdDataAccess', 'CoastAppLog'],
        'usedTarget'       : 'coastd.coastd',
        'copyFiles'        : [(SConsider.findFiles(['.', 'config'],['.txt', '.html', '.any', '.pem', '.gif', '.png', '.jpg', '.jpeg']), S_IRUSR|S_IRGRP|S_IROTH)],
        'runConfig'        : {
            'setUp': setUp,
            'tearDown': tearDown,
        },
    },
}

SConsider.createTargets(packagename, buildSettings)
