#include <stdio.h>
#include <string.h>

/*
  2.72 ◆◆
  You are given the task of writing a function that will copy an integer val into a
  buffer buf, but it should do so only if enough space is available in the buffer.

  Here is the code you write:

  // Copy integer into buffer if space is available
  // WARNING: The following code is buggy
  void copy_int(int val, void *buf, int maxbytes) {
      if (maxbytes-sizeof(val) >= 0)
      memcpy(buf, (void *) &val, sizeof(val));
  }

  This code makes use of the library function memcpy. Although its use is a bit
  artificial here, where we simply want to copy an int, it illustrates an approach
  commonly used to copy larger data structures.

  You carefully test the code and discover that it always copies the value to the
  buffer, even when maxbytes is too small.

  A. Explain why the conditional test in the code always succeeds. Hint: The
     sizeof operator returns a value of type size_t.
  B. Show how you can rewrite the conditional test to make it work properly.
*/

// Answers:
// A. sizeof(val) is size_t. size_t is unsigned, maxbytes gets implicitly cast to unsigned.
//    the result is unsigned and is always greater or equal than 0.

// B. Correct implementation. Even better, change the API so maxbytes is size_t in the first place.
// I think bound checking signed maxbytes is not practical for such a function, and should be done by
// the user of the function. size_t here would ensure correctness of the function itself
// (adherence to its advertised API) without any additional checks.
void copy_int(int val, void *buf, int maxbytes) {
    if ((size_t)maxbytes >= sizeof(val))
	memcpy(buf, (void *)&val, sizeof(val));
}

#define TEST_CASE(VAL, BUF, MAXBYTES) copy_int((VAL), (BUF), (MAXBYTES)), printf("copy_int(%d, %p, %d) => *((int *)buf)=%d\n", (VAL), (BUF), (MAXBYTES), *((int *)(BUF)));

int main() {
    char *bytes[128] = {};

    TEST_CASE(123, bytes, 128);
    TEST_CASE(238, bytes, 4);
    TEST_CASE(100101920, bytes, 4);
}

#undef TEST_CASE
