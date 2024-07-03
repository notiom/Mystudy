### 本节主要记录c#的学习过程

### c#在vscode中的编译命令
创建工程
```
dotnet new console -n MyProject
```
编译运行
```
dotnet run
```
数据类型主要有值类型，引用类型，指针类型
<br>
当一个值类型转换为对象类型时，则被称为 装箱；另一方面，当一个对象类型转换为值类型时，则被称为 拆箱。
<br>
字符串前加一个@可以逐字输出
<br>

# C#类型转换方法
ToInt16
<br>
静态变量是在类级别上声明的，但它们的作用域也受限于其定义的类。
<br>
在 C# 中，使用 ref 关键字声明引用参数。

# Array类的方法
```
1	Clear
根据元素的类型，设置数组中某个范围的元素为零、为 false 或者为 null。

2	Copy(Array, Array, Int32)
从数组的第一个元素开始复制某个范围的元素到另一个数组的第一个元素位置。长度由一个 32 位整数指定。

3	CopyTo(Array, Int32)
从当前的一维数组中复制所有的元素到一个指定的一维数组的指定索引位置。索引由一个 32 位整数指定。

4	GetLength
获取一个 32 位整数，该值表示指定维度的数组中的元素总数。

5	GetLongLength
获取一个 64 位整数，该值表示指定维度的数组中的元素总数。

6	GetLowerBound
获取数组中指定维度的下界。

7	GetType
获取当前实例的类型。从对象（Object）继承。

8	GetUpperBound
获取数组中指定维度的上界。

9	GetValue(Int32)
获取一维数组中指定位置的值。索引由一个 32 位整数指定。

10	IndexOf(Array, Object)
搜索指定的对象，返回整个一维数组中第一次出现的索引。

11	Reverse(Array)
逆转整个一维数组中元素的顺序。

12	SetValue(Object, Int32)
给一维数组中指定位置的元素设置值。索引由一个 32 位整数指定。

13	Sort(Array)
使用数组的每个元素的 IComparable 实现来排序整个一维数组中的元素。

14	ToString
返回一个表示当前对象的字符串。从对象（Object）继承。
```
# String类的方法
```
序号	方法名称 & 描述
1	public static int Compare( string strA, string strB )
比较两个指定的 string 对象，并返回一个表示它们在排列顺序中相对位置的整数。该方法区分大小写。

2	public static int Compare( string strA, string strB, bool ignoreCase )
比较两个指定的 string 对象，并返回一个表示它们在排列顺序中相对位置的整数。但是，如果布尔参数为真时，该方法不区分大小写。

3	public static string Concat( string str0, string str1 )
连接两个 string 对象。

4	public static string Concat( string str0, string str1, string str2 )
连接三个 string 对象。

5	public static string Concat( string str0, string str1, string str2, string str3 )
连接四个 string 对象。

6	public bool Contains( string value )
返回一个表示指定 string 对象是否出现在字符串中的值。

7	public static string Copy( string str )
创建一个与指定字符串具有相同值的新的 String 对象。

8	public void CopyTo( int sourceIndex, char[] destination, int destinationIndex, int count )
从 string 对象的指定位置开始复制指定数量的字符到 Unicode 字符数组中的指定位置。

9	public bool EndsWith( string value )
判断 string 对象的结尾是否匹配指定的字符串。

10	public bool Equals( string value )
判断当前的 string 对象是否与指定的 string 对象具有相同的值。

11	public static bool Equals( string a, string b )
判断两个指定的 string 对象是否具有相同的值。

12	public static string Format( string format, Object arg0 )
把指定字符串中一个或多个格式项替换为指定对象的字符串表示形式。

13	public int IndexOf( char value )
返回指定 Unicode 字符在当前字符串中第一次出现的索引，索引从 0 开始。

14	public int IndexOf( string value )
返回指定字符串在该实例中第一次出现的索引，索引从 0 开始。

15	public int IndexOf( char value, int startIndex )
返回指定 Unicode 字符从该字符串中指定字符位置开始搜索第一次出现的索引，索引从 0 开始。

16	public int IndexOf( string value, int startIndex )
返回指定字符串从该实例中指定字符位置开始搜索第一次出现的索引，索引从 0 开始。

17	public int IndexOfAny( char[] anyOf )

返回某一个指定的 Unicode 字符数组中任意字符在该实例中第一次出现的索引，索引从 0 开始。
18	public int IndexOfAny( char[] anyOf, int startIndex )
返回某一个指定的 Unicode 字符数组中任意字符从该实例中指定字符位置开始搜索第一次出现的索引，索引从 0 开始。

19	public string Insert( int startIndex, string value )
返回一个新的字符串，其中，指定的字符串被插入在当前 string 对象的指定索引位置。

20	public static bool IsNullOrEmpty( string value )
指示指定的字符串是否为 null 或者是否为一个空的字符串。

21	public static string Join( string separator, string[] value )
连接一个字符串数组中的所有元素，使用指定的分隔符分隔每个元素。

22	public static string Join( string separator, string[] value, int startIndex, int count )
连接一个字符串数组中的指定位置开始的指定元素，使用指定的分隔符分隔每个元素。

23	public int LastIndexOf( char value )
返回指定 Unicode 字符在当前 string 对象中最后一次出现的索引位置，索引从 0 开始。

24	public int LastIndexOf( string value )
返回指定字符串在当前 string 对象中最后一次出现的索引位置，索引从 0 开始。

25	public string Remove( int startIndex )
移除当前实例中的所有字符，从指定位置开始，一直到最后一个位置为止，并返回字符串。

26	public string Remove( int startIndex, int count )
从当前字符串的指定位置开始移除指定数量的字符，并返回字符串。

27	public string Replace( char oldChar, char newChar )
把当前 string 对象中，所有指定的 Unicode 字符替换为另一个指定的 Unicode 字符，并返回新的字符串。

28	public string Replace( string oldValue, string newValue )
把当前 string 对象中，所有指定的字符串替换为另一个指定的字符串，并返回新的字符串。

29	public string[] Split( params char[] separator )
返回一个字符串数组，包含当前的 string 对象中的子字符串，子字符串是使用指定的 Unicode 字符数组中的元素进行分隔的。

30	public string[] Split( char[] separator, int count )
返回一个字符串数组，包含当前的 string 对象中的子字符串，子字符串是使用指定的 Unicode 字符数组中的元素进行分隔的。int 参数指定要返回的子字符串的最大数目。

31	public bool StartsWith( string value )
判断字符串实例的开头是否匹配指定的字符串。

32	public char[] ToCharArray()
返回一个带有当前 string 对象中所有字符的 Unicode 字符数组。

33	public char[] ToCharArray( int startIndex, int length )
返回一个带有当前 string 对象中所有字符的 Unicode 字符数组，从指定的索引开始，直到指定的长度为止。

34	public string ToLower()
把字符串转换为小写并返回。

35	public string ToUpper()
把字符串转换为大写并返回。

36	public string Trim()
移除当前 String 对象中的所有前导空白字符和后置空白字符。
```

析构函数不能继承和重载
<br>
关键字 static 意味着类中只有一个该成员的实例。

### abstract关键字
<br>
您不能创建一个抽象类的实例。
<br>
您不能在一个抽象类外部声明一个抽象方法。
<br>
通过在类定义前面放置关键字 sealed，可以将类声明为密封类。当一个类被声明为 sealed 时，它不能被继承。抽象类不能被声明为 sealed。
<br>

### var关键字
var关键字 1.必须在局部作用域内使用 2.必须在定义时初始化 3.在整个过程中类型不会被改变

### ArrayList
```
1	public virtual int Add( object value );
在 ArrayList 的末尾添加一个对象。

2	public virtual void AddRange( ICollection c );
在 ArrayList 的末尾添加 ICollection 的元素。

3	public virtual void Clear();
从 ArrayList 中移除所有的元素。

4	public virtual bool Contains( object item );
判断某个元素是否在 ArrayList 中。

5	public virtual ArrayList GetRange( int index, int count );
返回一个 ArrayList，表示源 ArrayList 中元素的子集。

6	public virtual int IndexOf(object);
返回某个值在 ArrayList 中第一次出现的索引，索引从零开始。

7	public virtual void Insert( int index, object value );
在 ArrayList 的指定索引处，插入一个元素。

8	public virtual void InsertRange( int index, ICollection c );
在 ArrayList 的指定索引处，插入某个集合的元素。

9	public virtual void Remove( object obj );
从 ArrayList 中移除第一次出现的指定对象。

10	public virtual void RemoveAt( int index );
移除 ArrayList 的指定索引处的元素。

11	public virtual void RemoveRange( int index, int count );
从 ArrayList 中移除某个范围的元素。

12	public virtual void Reverse();
逆转 ArrayList 中元素的顺序。

13	public virtual void SetRange( int index, ICollection c );
复制某个集合的元素到 ArrayList 中某个范围的元素上。

14	public virtual void Sort();
对 ArrayList 中的元素进行排序。

15	public virtual void TrimToSize();
设置容量为 ArrayList 中元素的实际个数。
```

### Hashtable
```
1	public virtual void Add( object key, object value );
向 Hashtable 添加一个带有指定的键和值的元素。

2	public virtual void Clear();
从 Hashtable 中移除所有的元素。

3	public virtual bool ContainsKey( object key );
判断 Hashtable 是否包含指定的键。

4	public virtual bool ContainsValue( object value );
判断 Hashtable 是否包含指定的值。

5	public virtual void Remove( object key );
从 Hashtable 中移除带有指定的键的元素。
```
