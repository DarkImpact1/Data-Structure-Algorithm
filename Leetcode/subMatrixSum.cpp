int subMatrixSum(vector<vector<int>> &matrix){
    int m = 1e9+7;
    int row = matrix.size();
    int col = matrix[0].size();
    int sum = 0;
    for(int r=0; r<row; r++){
        for(int c=0; c<col; c++){
            int top_left_corner_choices = (((r+1)%m)*((c+1)%m))%m;
            int bottom_right_corner_choice = (((n-r)%m)*((n-c)%m))%m;
            int total_choice = ((top_left_corner_choices%m)*(bottom_right_corner_choice%m)%m);
            sum += ((matrix[r][c]%m)*(total_contri%m))%m;
        }
    }
    return sum;
    
}
