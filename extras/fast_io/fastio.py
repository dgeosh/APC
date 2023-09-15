# Function for Fast Input
def fast_io():
    
    # Reinitialize the Input function
    input = io.BytesIO(os.read(0, \
         os.fstat(0).st_size)).readline
  
    # Taking input as string 
    s = input().decode()

    return s
