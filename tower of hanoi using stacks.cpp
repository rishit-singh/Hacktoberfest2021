#include &lt;iostream&gt;
#include &lt;bits/stdc++.h&gt;
using namespace std;
struct Stack
{
unsigned capacity;
int top;
int *array;
};

struct Stack* createStack(unsigned capacity)
{
struct Stack* stack =
(struct Stack*) malloc(sizeof(struct Stack));
stack -&gt; capacity = capacity;
stack -&gt; top = -1;
stack -&gt; array =
(int*) malloc(stack -&gt; capacity * sizeof(int));
return stack;

}

int isFull(struct Stack* stack)
{
return (stack-&gt;top == stack-&gt;capacity - 1);
}

int isEmpty(struct Stack* stack)
{
return (stack-&gt;top == -1);
}

void push(struct Stack *stack, int item)
{
if (isFull(stack))
return;
stack -&gt; array[++stack -&gt; top] = item;
}

int pop(struct Stack* stack)
{
if (isEmpty(stack))

return INT_MIN;
return stack -&gt; array[stack -&gt; top--];
}

void moveDisk(char fromPeg, char toPeg, int disk)
{
cout &lt;&lt;&quot;Move the disk &quot; &lt;&lt; disk &lt;&lt;&quot; from &quot; &lt;&lt; fromPeg
&lt;&lt; &quot; to &quot;&lt;&lt; toPeg &lt;&lt; endl;
}

void moveDisksBetweenTwoPoles(struct Stack *src,
struct Stack *dest, char s, char d)

{
int pole1TopDisk = pop(src);
int pole2TopDisk = pop(dest);

if (pole1TopDisk == INT_MIN)
{
push(src, pole2TopDisk);
moveDisk(d, s, pole2TopDisk);
}

else if (pole2TopDisk == INT_MIN)
{
push(dest, pole1TopDisk);
moveDisk(s, d, pole1TopDisk);
}

else if (pole1TopDisk &gt; pole2TopDisk)
{
push(src, pole1TopDisk);
push(src, pole2TopDisk);
moveDisk(d, s, pole2TopDisk);
}

else
{
push(dest, pole2TopDisk);
push(dest, pole1TopDisk);
moveDisk(s, d, pole1TopDisk);
}
}

void tohIterative(int num_of_disks, struct Stack

*src, struct Stack *aux,
struct Stack *dest)

{
int i, total_num_of_moves;
char s = &#39;S&#39;, d = &#39;D&#39;, a = &#39;A&#39;;

if (num_of_disks % 2 == 0)
{
char temp = d;
d = a;
a = temp;
}
total_num_of_moves = pow(2, num_of_disks) - 1;

for (i = num_of_disks; i &gt;= 1; i--)
push(src, i);

for (i = 1; i &lt;= total_num_of_moves; i++)
{
if (i % 3 == 1)
moveDisksBetweenTwoPoles(src, dest, s, d);

else if (i % 3 == 2)
moveDisksBetweenTwoPoles(src, aux, s, a);

else if (i % 3 == 0)
moveDisksBetweenTwoPoles(aux, dest, a, d);
}
}

int main()
{

unsigned num_of_disks = 3;

struct Stack *src, *dest, *aux;

src = createStack(num_of_disks);
aux = createStack(num_of_disks);
dest = createStack(num_of_disks);

tohIterative(num_of_disks, src, aux, dest);
return 0;
}
