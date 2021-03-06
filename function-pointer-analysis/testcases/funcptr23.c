int add(int a, int b) {
   return a+b;
}

int sub(int a, int b) {
   return a-b;
}

int goo(int a, int b, int (*a_fptr)(int, int), int(*b_fptr)(int, int) ) {
   int (*s_fptr)(int, int);
   if (a > 0) 
      s_fptr = a_fptr;
   else
      s_fptr = b_fptr;
   return s_fptr(a, b);
}

int foo(int a, int b, int (*a_fptr)(int, int), int(*b_fptr)(int, int)) {
    return goo(a, b, a_fptr, b_fptr);
}


int moo(char x, int op1, int op2) {
    int (*a_fptr)(int, int) = add;
    int (*s_fptr)(int, int) = sub;
    int (*t_fptr)(int, int) = 0;

    if (x == '+') {
       t_fptr = a_fptr;
    } 
    else if (x == '-') {
       t_fptr = s_fptr;
    }

    unsigned result = foo(op1, op2, a_fptr, t_fptr);
    return 0;
}

/// 15 : add, sub
/// 19 : goo
/// 35 : foo
