#include "../include/builtins.h"
#include "../include/shell.h"

char *builtin_str[] = {"cd", "help", "exit", "export", "unset"};

int (*builtin_func[])(char **) = {&arsh_cd, &arsh_help, &arsh_exit,
                                  &arsh_export, &arsh_unset};

int arsh_num_biultins() { return sizeof(builtin_str) / sizeof(char *); }

int arsh_cd(char **args) {
  if (args[1] == NULL)
    fprintf(stderr, "arsh: expected argument to \"cd\"\n");
  else {
    if (chdir(args[1]) != 0) {
      perror("arsh");
    }
  }
  return 1;
}

int arsh_help(char **args) {
  (void)args;
  printf("==================================================\n");
  printf("                  ARSH SHELL HELP                 \n");
  printf("==================================================\n");
  printf("Type program names and arguments, and hit enter.\n\n");

  printf("Built-in Commands:\n");
  printf("  cd [dir]       : Change the current directory\n");
  printf("  help           : Display this help message\n");
  printf("  exit           : Exit the shell\n");
  printf("  export KEY=VAL : Set an environment variable\n");
  printf("  unset KEY      : Unset an environment variable\n\n");

  printf("Shell Features:\n");
  printf("  > file         : Redirect output to a file (overwrite)\n");
  printf("  >> file        : Redirect output to a file (append)\n");
  printf("  < file         : Redirect input from a file\n");
  printf("  cmd1 | cmd2    : Pipe output of cmd1 to cmd2\n");
  printf("  cmd1 && cmd2   : Run cmd2 only if cmd1 succeeds\n");
  printf("  cmd1 || cmd2   : Run cmd2 only if cmd1 fails\n");
  printf("  cmd &          : Run command in background\n");
  printf("  * ?            : Wildcard expansion (globbing)\n");
  printf("  $VAR           : Environment variable expansion\n");
  printf("  $?             : Exit status of the last command\n\n");

  printf("Use 'man' for information on other programs.\n");
  printf("==================================================\n");
  return 1;
}

int arsh_exit(char **args) {
  (void)args;
  return 0;
}

int arsh_export(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "arsh: expected argument to \"export\"\n");
  }

  // split KEY=VALUE string
  char *arg = args[1];
  char *equal_sign = strchr(arg, '=');

  if (equal_sign == NULL) {
    fprintf(stderr, "arsh: invalid format (use KEY=VALUE)\n");
    return 1;
  }
  // terminate key string at the '='
  *equal_sign = '\0';

  char *key = arg;
  char *value = equal_sign + 1;

  if (setenv(key, value, 1) != 0) {
    perror("arsh");
  }
  return 1;
}

int arsh_unset(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "arsh: expected argument to \"unset\"\n");
    return 1;
  }

  if (unsetenv(args[1]) != 0) {
    perror("arsh");
  }

  return 1;
}
