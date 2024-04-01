'''
写一个类似于装饰器框架的函数,注册表将所有函数的类全部加载进来
'''
class Registry():
    '''
    定义注册表函数
    '''
    def __init__(self,name):
        self._name__ = name
        self._obj_map = {}
        self._suffix = None

    def _do_register(self,name,obj):
        '''
        用于区分是否是同一个对象,注意这里的name和init中定义的self._name不同
        '''
        if isinstance(self._suffix,str):
            #添加一个类的副本，防止类名重复无法创建
            name = name + '_' + self._suffix
        i = 1
        while(name in self._obj_map):
            name = name + '_' + f'{i}'
            i +=1
        self._obj_map[name] = obj

    def register(self,obj = None,suffix = None):
        self._obj = obj
        self._suffix = suffix

        if obj is None:
            # 这里使用一个装饰器
            def deco(func_or_class):
                name = func_or_class.__name__
                #这里是对装饰函数进行修饰，增加一些功能,将自己作为一个对象传入
                self._do_register(name,func_or_class)
                #将被装饰完的函数返回
                return func_or_class
            return deco
         # used as a function call
        name = obj.__name__
        self._do_register(name, obj, suffix)

    def get(self,name):
        ret = self._obj_map.get(name)
        if(ret is None):
            print(f'Name {name} is not found!')
            raise KeyError((f"No object named '{name}' found in '{self._name}' registry!"))
        return ret
    
    def __contains__(self, name):
        '''
        当使用 name in registry 这样的语句时，
        实际上就会调用这个方法来检查指定的名称是否存在于注册表中。
        '''
        return name in self._obj_map
    def __iter__(self):
        '''
        转化为迭代器对象
        '''
        return iter(self._obj_map.items())

    def keys(self):
        return self._obj_map.keys()
    
abc = Registry('2b')

@abc.register()
class ABV:
    def __init__(self,name = 'xiaoyao'):
        self.name = name
        self._print()
    def _print(self):
        print(f'{self.name} is sb!')

print('ABV' in abc)
for item in abc:
    print(item)
print(abc.keys())

abv = ABV('languo')

