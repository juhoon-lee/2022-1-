-- 물품ID, 물품명, 가격, 평점, 재고, 그리고 고객이 작성한 모든 리뷰를 출력한다.
CREATE OR REPLACE PROCEDURE show_review (s_kind IN varchar(30))
AS
    x_costomer  varchar(20);
    x_product_name varchar(20);
    x_grade numeric(2.0);
    x_review varchar(50);
    
  CURSOR c1 is
      SELECT c_id, p_ID, grade, review
      FROM evaluation A, 
      WHERE ID = s_id
BEGIN
    select name, dept_name into x_name, x_dept_name
    from student
    where ID = s_id;
    
    dbms_output.put_line (s_id||'   '||x_name||'   '||x_dept_name);
    
    open c1;
    loop
        FETCH c1 INTO x_course_id, x_semester, x_year, x_grade;
        EXIT WHEN c1%NOTFOUND;
        select title into x_title
        from course
        where course_id = x_course_id;
        dbms_output.put_line ('       '||x_course_id||'  '||x_title||'  '||x_semester||'  '||x_year||'   '||x_grade);
    end loop;
    close c1;
END;