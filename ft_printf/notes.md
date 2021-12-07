### `%d` type

`-` flag overrides the `0` flag

`+` flag overrides the _`space character`_ flag

`.` _aka_ precision field overrides the `0` flag

if `.` _aka_ precision length is bigger than the input 
length, the rest is filled with _`0`'s_

else if `.` _aka_ presicion length is smaller than the 
input length, the input should be fully printed, without 
truncation

the `#` flag doesn't work with the `%d` type

### `%c` type

- `+` flag **doesn't** work with `%c` type
- `0` flag **doesn't** work with `%c` type
- `-` flag **does** work with the `%c` type
- `space` flag **doesn't** work with the `%c` type
- `.` flag **doesn't** work with the '%c' type
- `#` flag doesn't work with the `%c` type
