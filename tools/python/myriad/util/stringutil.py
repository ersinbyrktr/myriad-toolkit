'''
This file is licensed unter the PSF License. For more information about the 
license, please refer to

    http://docs.python.org/license.html

@author: alane@sourceforge.net.

The original algorithm for this component was provided by Xavier Defrang.
http://aspn.activestate.com/ASPN/Cookbook/Python/Recipe/81330. 
'''

import re
import UserDict

# Original algorithm by Xavier Defrang.
# http://aspn.activestate.com/ASPN/Cookbook/Python/Recipe/81330
# This implementation by alane@sourceforge.net.

class TextSub(UserDict.UserDict):
    def __init__(self, dicttionary = None):
        self.re = None
        self.regex = None
        UserDict.UserDict.__init__(self, dicttionary)
        
    def compile(self):
        if len(self.data) > 0:
            tmp = "(%s)" % "|".join(map(re.escape, map(self.formatKey, self.data.keys())))
            if self.re != tmp:
                self.re = tmp
                self.regex = re.compile(self.re)

    def __call__(self, match):
        return self.data[match.string[match.start()+1:match.end()-1]]

    def sub(self, s):
        if len(self.data) == 0:
            return s
        return self.regex.sub(self, s)

    def formatKey(self, key):
        return "{%s}" %(key)
    
def processTemplate(inPath, outPath, params):
    writeString(outPath, params.sub(readString(inPath)))

def writeString(path, s):
    f = open(path, 'w')
    f.write(s)
    
def readString(path):
    f = open(path, 'r')
    return "".join(f.readlines())
    
def readFirstLine(path):
    f = open(path, 'r')
    return f.readline()

class StringTransformer(object):
    '''
    classdocs
    '''
    
    _cc2us_pattern1 = re.compile('(.)([A-Za-z]+)')
    _cc2us_pattern2 = re.compile('([a-z0-9])([A-Z])')
    
    @staticmethod
    def uc(s):
        return s.upper()
    
    @staticmethod
    def lc(s):
        return s.lower()
    
    @staticmethod
    def cc2us(s):
        return StringTransformer._cc2us_pattern2.sub(r'\1_\2', StringTransformer._cc2us_pattern1.sub(r'\1_\2', s)).lower()
    
    @staticmethod
    def us2cc(s):
        def camelcase(): 
            yield str.lower
            while True:
                yield str.capitalize
    
        c = camelcase()
        return "".join(c.next()(x) if x else '_' for x in s.split("_"))
    
    @staticmethod
    def us2ccAll(s):
        return StringTransformer.ucFirst(StringTransformer.us2cc(s))
    
    @staticmethod
    def ucFirst(s):
        return "%s%s" % (s[0].capitalize(), s[1:])