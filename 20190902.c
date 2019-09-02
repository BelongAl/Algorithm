bool isLongPressedName(char * name, char * typed)
{
  while(*typed != '\0')
  {
    if(*typed == *name)
    {
      name++;
    }
    if(*name == '\0')
    {
      return true;
    }
    typed++;
  }
  return false;
}
