# OS_Assignement1

Michael Kulinich
kulinich@chapman.edu

Ayden Best
bbest@chapman.edu

CPSC 380-01
Assignment 1


//       strace output          //

    execve("./filecpy", ["./filecpy", "./test.txt", "./output.txt"], [/* 13 vars */]) = 0
    brk(NULL)                               = 0x563bfd135000
    access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
    mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7efe98090000
    access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
    open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
    fstat(3, {st_mode=S_IFREG|0644, st_size=29464, ...}) = 0
    mmap(NULL, 29464, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7efe98088000
    close(3)                                = 0
    access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
    open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
    read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\4\2\0\0\0\0\0"..., 832) = 832
    fstat(3, {st_mode=S_IFREG|0755, st_size=1689360, ...}) = 0
    mmap(NULL, 3795296, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7efe97ad0000

    mprotect(0x7efe97c65000, 2097152, PROT_NONE) = 0
    mmap(0x7efe97e65000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x195000) = 0x7efe97e65000
    mmap(0x7efe97e6b000, 14688, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7efe97e6b000
    close(3)                                = 0
    mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7efe98096000
    arch_prctl(ARCH_SET_FS, 0x7efe98096700) = 0
    mprotect(0x7efe97e65000, 16384, PROT_READ) = 0
    mprotect(0x563bfc132000, 4096, PROT_READ) = 0
    mprotect(0x7efe98093000, 4096, PROT_READ) = 0
    munmap(0x7efe98088000, 29464)           = 0
    fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 0), ...}) = 0
    brk(NULL)                               = 0x563bfd135000
    brk(0x563bfd156000)                     = 0x563bfd156000
    write(1, "Given Input file: ./test.txt\n", 29Given Input file: ./test.txt
    ) = 29
    write(1, "Output file: ./output.txt\n", 26Output file: ./output.txt
    ) = 26
    open("./test.txt", O_RDONLY)            = 3
    write(1, "File ./test.txt succesfully foun"..., 34File ./test.txt succesfully found
    ) = 34
    open("./output.txt", O_WRONLY|O_CREAT|O_EXCL, 0700) = 4
    write(1, "File ./output.txt succesfully cr"..., 38File ./output.txt succesfully created
    ) = 38
    read(3, "12fwreqff421\r\n42f\r\n21f4g21g4312\r"..., 512) = 56
    write(4, "12fwreqff421\r\n42f\r\n21f4g21g4312\r"..., 56) = 56
    read(3, "", 512)                        = 0
    close(3)                                = 0
    close(4)                                = 0
    write(1, "Successfully completed\n", 23Successfully completed
    ) = 23
    exit_group(0)                           = ?
    +++ exited with 0 +++
