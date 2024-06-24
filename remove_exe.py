import os

def delete_exe_files(directory):
    # Walk through the directory tree
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith('.exe'):
                file_path = os.path.join(root, file)
                try:
                    os.remove(file_path)
                    print(f"Deleted: {file_path}")
                except Exception as e:
                    print(f"Error deleting {file_path}: {e}")

# Get the current working directory
current_directory = os.getcwd()

# Delete all .exe files in the current directory and its subdirectories
delete_exe_files(current_directory)
