func solution(_ n:Int64) -> Int64 {
    for i in 1...50000000000000/4 {
        if i*i == n {return Int64((i+1)*(i+1))}
        else if i*i > n {return Int64(-1)}
    }
    return 0
}
