DECLARE
    t_deptName VARCHAR(30); -- 학과 이름
    t_name VARCHAR(30); -- 학생 이름
    t_title VARCHAR(30); -- 과목 이름
    t_credits numeric(1,0); -- 학점
    t_semester varchar(10); -- 학기
    t_year numeric(4,0); -- 년도
    t_Grade varchar(5); -- 성적
    t_totalCredit numeric(2,0); -- 전체 학점
    t_titleCount numeric(3.1); -- 수강 과목 카운트
    t_gpa numeric(3,1); -- 평점

    CURSOR c0 is -- 학과 분류 
        SELECT distinct dept_name
        FROM student
        order by dept_name;

    CURSOR c1 is -- 학생 분류
        SELECT name
        FROM student
        WHERE student.dept_name = t_deptName
        order by name;

    Cursor c2 is -- 학생별 수강 과목
        select title, credits, semester, year, grade
        from student natural join takes join course using(course_id)
        WHERE name = t_name -- c1에서 t_name에 할당한 이름만 거르기
        order by year, semester desc;

BEGIN
    -- c0 루프 시작
    OPEN c0;
    loop
        fetch c0 into t_deptName;
        exit when c0%NOTFOUND;
        dbms_output.put_line(t_deptName);

        -- c1 루프 시작
        OPEN c1;
        LOOP
            FETCH c1 INTO t_name;
            EXIT WHEN c1%NOTFOUND;
            dbms_output.put_line('    '||t_name);
            -- c2 루프 시작
            t_totalCredit := 0;
            t_titleCount := 0;
            t_gpa := 0;
            OPEN c2;
                LOOP
                    FETCH c2 INTO t_title, t_credits, t_semester, t_year, t_Grade;
                    EXIT WHEN c2%NOTFOUND;
                    t_titleCount := t_titleCount + 1;
                    IF t_Grade is null
                    THEN t_Grade := '-';
                    t_titleCount := t_titleCount - 1;
                    END IF;
                    dbms_output.put_line('        '||RPAD(t_title,30,' ')||t_credits||'  '||RPAD(t_semester,6,' ')||'  '||t_year||'  '||t_Grade);
                    t_totalCredit := t_totalCredit + t_credits;
                    IF t_Grade = 'A+' -- gpa에 일단 모든 점수를 더한 후 LOOP 종료후 계산
                        THEN t_gpa := t_gpa + 4.3;
                    ELSIF t_Grade = 'A'
                        THEN t_gpa := t_gpa + 4;
                    ELSIF t_Grade = 'A-'
                        THEN t_gpa := t_gpa + 3.7;
                    ELSIF t_Grade = 'B+'
                        THEN t_gpa := t_gpa + 3.3;
                    ELSIF t_Grade = 'B'
                        THEN t_gpa := t_gpa + 3;
                    ELSIF t_Grade = 'B-'
                        THEN t_gpa := t_gpa + 2.7;
                    ELSIF t_Grade = 'C+'
                        THEN t_gpa := t_gpa + 2.3;
                    ELSIF t_Grade = 'C'
                        THEN t_gpa := t_gpa + 2;
                    ELSIF t_Grade = 'C-'
                        THEN t_gpa := t_gpa + 1.7;
                    ELSIF t_Grade = 'D+'
                        THEN t_gpa := t_gpa + 1.3;
                    ELSIF t_Grade = 'D'
                        THEN t_gpa := t_gpa + 1;
                    ELSIF t_Grade = 'D-'
                        THEN t_gpa := t_gpa + 0.7;
                    ELSIF t_Grade = 'F'
                        THEN null;
                    END IF;
                END LOOP;
            CLOSE c2;
            IF t_titleCount = 0 -- 수강한 과목이 없는 학생 Exeption
            THEN t_gpa := 0;
            ELSE
            t_gpa := t_gpa / t_titleCount; -- gpa 계산
            END IF;
            dbms_output.put_line('        '||'Total Credit: '||t_totalCredit||'  '||'GPA: '||t_gpa);
        END LOOP;
        CLOSE c1;
    end loop;
    CLOSE c0;
END;