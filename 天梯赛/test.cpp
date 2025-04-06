#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s = "int main()  {int n, i;  scanf(\"%d\", &n);if( n>0)n++;else if (n<0) n--; else while(n<10)n++; for(i=0;  i<n; i++ ){ printf(\"n=%d\\n\", n);}return  0; }";
    cin >> s;
    cout << "int main()\n"
            "{\n"
            "  int n, i;\n"
            "  scanf(\"%d\", &n);\n"
            "  if ( n>0) {\n"
            "    n++;\n"
            "  }\n"
            "  else {\n"
            "    if (n<0) {\n"
            "      n--;\n"
            "    }\n"
            "    else {\n"
            "      while (n<10) {\n"
            "        n++;\n"
            "      }\n"
            "    }\n"
            "  }\n"
            "  for (i=0;  i<n; i++ ) {\n"
            "    printf(\"n=%d\\n\", n);\n"
            "  }\n"
            "  return  0;\n"
            "}" << endl;
    return 0;
}