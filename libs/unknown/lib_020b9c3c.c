/* Script command wrappers; contracts are supported by the original ARM calls. */
/* Read a signed word operand from the current script; callers use indices 0 and 1. */
extern int func_0203ac00(int operandIndex);
/* Dispatch four word arguments via the shared work record and return its result. */
extern int func_020b8b38(int command, int operand0, int operand1, int operand2);
/* Publish the result in the current script context and clear its result-kind byte. */
extern void func_0203acf4(int result);

/* Original 0x020b9c3c: read operands 0 and 1, dispatch command 80,
 * publish the dispatch result through func_0203acf4, and return script status 1.
 * No explicit arguments: operands come from the current script context. */
int func_020b9c3c(void)
{
    int operand0 = func_0203ac00(0);
    int operand1 = func_0203ac00(1);
    func_0203acf4(func_020b8b38(80, operand0, operand1, 0));
    return 1;
}

/* Original 0x020b9c74: read operands 0 and 1, dispatch command 81,
 * publish the dispatch result through func_0203acf4, and return script status 1.
 * No explicit arguments: operands come from the current script context. */
int func_020b9c74(void)
{
    int operand0 = func_0203ac00(0);
    int operand1 = func_0203ac00(1);
    func_0203acf4(func_020b8b38(81, operand0, operand1, 0));
    return 1;
}

/* Original 0x020b9cac: read operands 0 and 1, dispatch command 82,
 * publish the dispatch result through func_0203acf4, and return script status 1.
 * No explicit arguments: operands come from the current script context. */
int func_020b9cac(void)
{
    int operand0 = func_0203ac00(0);
    int operand1 = func_0203ac00(1);
    func_0203acf4(func_020b8b38(82, operand0, operand1, 0));
    return 1;
}

/* Original 0x020b9ce4: read operands 0 and 1, dispatch command 83,
 * publish the dispatch result through func_0203acf4, and return script status 1.
 * No explicit arguments: operands come from the current script context. */
int func_020b9ce4(void)
{
    int operand0 = func_0203ac00(0);
    int operand1 = func_0203ac00(1);
    func_0203acf4(func_020b8b38(83, operand0, operand1, 0));
    return 1;
}

/* Original 0x020b9d8c: read operand 0, dispatch command 86,
 * publish the dispatch result through func_0203acf4, and return script status 1.
 * No explicit arguments: operands come from the current script context. */
int func_020b9d8c(void)
{
    int operand0 = func_0203ac00(0);
    func_0203acf4(func_020b8b38(86, operand0, 0, 0));
    return 1;
}

/* Original 0x020b9db8: read operand 0, dispatch command 87,
 * publish the dispatch result through func_0203acf4, and return script status 1.
 * No explicit arguments: operands come from the current script context. */
int func_020b9db8(void)
{
    int operand0 = func_0203ac00(0);
    func_0203acf4(func_020b8b38(87, operand0, 0, 0));
    return 1;
}

/* Original 0x020b9de4: read operand 0, dispatch command 88,
 * publish the dispatch result through func_0203acf4, and return script status 1.
 * No explicit arguments: operands come from the current script context. */
int func_020b9de4(void)
{
    int operand0 = func_0203ac00(0);
    func_0203acf4(func_020b8b38(88, operand0, 0, 0));
    return 1;
}

/* Original 0x020b9e10: read operand 0, dispatch command 89,
 * publish the dispatch result through func_0203acf4, and return script status 1.
 * No explicit arguments: operands come from the current script context. */
int func_020b9e10(void)
{
    int operand0 = func_0203ac00(0);
    func_0203acf4(func_020b8b38(89, operand0, 0, 0));
    return 1;
}

