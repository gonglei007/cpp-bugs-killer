<h2 align="center">C++找bug训练</h2>

# 运算符
## Bug1
### 代码
```
如果 'pceltFetched' 不是一个空指针，该函数必须增加该指针指向的ULONG类型变量的值。
这段代码有什么问题？
STDMETHODIMP CCustomAutoComplete::Next(..., ULONG *pceltFetched)
{
  ...
  if (pceltFetched != NULL)
    *pceltFetched++;
  ...
} 
```

### 说明
```
'++' 运算符的优先级高于 '*' 运算符的优先级（指针解引用）。该 "*pceltFetched++;" 行等同于下面的代码：
TMP = pceltFetched + 1;
*pceltFetched;
pceltFetched = TMP;
实际上它仅仅增加了指针的值。
为使代码正确，我们必须添加括号："(*pceltFetched)++;".

```


# if流程控制
## Bug1
### 代码
```
这段代码有什么问题？
void BCMenu::InsertSpaces(void)
{
  if(IsLunaMenuStyle())
    if(!xp_space_accelerators) return;
  else
    if(!original_space_accelerators) return;
  ...
}
```

### 说明
```
// 我们希望的逻辑是
if(IsLunaMenuStyle()) {
  if(!xp_space_accelerators) return;
} else {
  if(!original_space_accelerators) return;
}

// 但实际逻辑是
if(IsLunaMenuStyle())
{
   if(!xp_space_accelerators) {
     return;
   } else {
     if(!original_space_accelerators) return;
   }
}


```

# loop流程控制
## Bug1
### 代码
```
这段代码有什么问题？
bool equals( class1* val1, class2* val2 ) const{
{
  ...
  size_t size = val1->size();
  ...
  while ( --size >= 0 ){
    if ( !comp(*itr1,*itr2) )
      return false;
    itr1++;
    itr2++;
  }
  ...
}
```

### 说明
```
// size变量是无符号类型的，所以(--size >= 0) 条件总为 true.
建议这样写
for (size_t i = 0; i != size; i++){
  if ( !comp(*itr1,*itr2) )
    return false;
  itr1++;
  itr2++;
}

```

# 内存
## Bug1
### 代码
```
class Complex
{
	public:
	double real, imag;
	Complex();
};

Complex& operator+( Complex& a, Complex& b)
{
	Complex *p = new Complex;
	p->real = a.real + b.real;
	p->imag = a.imag + b.imag;
	return *p;
}
```

### 说明
```
binary operator 'Symbol' returning a reference  -- An
       operator-like function was found to be returning a reference.
       For example:

                 X &operator+ ( X &, X & );

       This is almost always a bad idea.  [12, Item 23].  You normally
       can't return a reference unless you allocate the object, but then
       who is going to delete it.  The usual way this is declared is:

                 X operator+ ( X &, X & );
```


