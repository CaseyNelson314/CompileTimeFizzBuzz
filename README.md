# CompileTimeFizzBuzz

コンパイル時 FizzBuzz

```sh
git clone https://github.com/CaseyNelson314/CompileTimeFizzBuzz.git
cd CompileTimeFizzBuzz
g++ .\main.cpp -o main && ./main
```

## 仕組み

次のソースコードはコンパイル時に出力処理の部分のみに展開されます。

```cpp
int main()
{
    FizzBazz<100>::Print();
}
```

↓

```cpp
int main()
{
    std::cout << 1      << std::endl;
    std::cout << 2      << std::endl;
    std::cout << "Fizz" << std::endl;
    std::cout << 4      << std::endl;
    std::cout << "Buzz" << std::endl;
    std::cout << "Fizz" << std::endl;
    std::cout << 7      << std::endl;
    std::cout << 8      << std::endl;
    std::cout << "Fizz" << std::endl;
    std::cout << "Buzz" << std::endl;
    ...
}
```

---

カウントアップ部

```cpp
// FizzBuzz エントリーポイント
template <int N, int Count = 1>
struct FizzBazz
{
    static void Print()
    {
        FizzBazzImpl<Count, Count % 3, Count % 5>::Print();  // FizzBuzz部呼び出し
        FizzBazz<N, Count + 1>::Print();   // 再帰呼び出し
    }
};

// カウント数と出力数 (カウント上限) が一致する場合終了
template <int N>
struct FizzBazz<N, N>
{
    static void Print() { }
};
```

---

FizzBuzz 部 

部分特殊化祭り

```cpp
template <int N, int, int>
struct FizzBazzImpl
{
    static void Print() { std::cout << N << std::endl; }
};

template <int N>
struct FizzBazzImpl<N, 0, 0>  // Count % 3 == 0  &&  Count % 5 == 0
{
    static void Print() { std::cout << "FizzBuzz" << std::endl; }
};

template <int N, int Mod5>
struct FizzBazzImpl<N, 0, Mod5>  // Count % 3 == 0
{
    static void Print() { std::cout << "Fizz" << std::endl; }
};

template <int N, int Mod3>
struct FizzBazzImpl<N, Mod3, 0>  // Count % 5 == 0
{
    static void Print() { std::cout << "Buzz" << std::endl; }
};
```
