<link rel="shortcut icon" href="http://physics.unm.edu/pandaweb/common/images/unm.ico" />
<link href="http://physics.unm.edu/pandaweb/common/stylesheets/base.css" rel="stylesheet" type="text/css" media="screen" />
<link href="http://physics.unm.edu/pandaweb/common/stylesheets/print.css" rel="stylesheet" type="text/css" media="print" />
<!--[if lt IE 7]>
  <link rel="stylesheet" type="text/css" media="screen" href="http://physics.unm.edu/pandaweb/common/stylesheets/ie.css" />
<![endif]-->
<!-- TemplateBeginEditable name="head" --><!-- TemplateEndEditable -->
<!--<script type="text/javascript" src="../common/javascript/menu_status.js"></script>   -->
<div id="leftnav">
      <div class="no_slidemenu_container">
      <div class="no_slidemenu">
<?php
include_once  '/nfs/user/p/physics/Sites/physics.unm.edu/app.php';
dbOpen();

$query = "
	SELECT		CONCAT(first_name,' ',middle_name,' ',last_name) AS allnames,
				email_address,
                url_image,
				title_primary,
                office_primary,
                phone_primary,
                degree_institution_primary,
                degree_year_primary,
		        panda_roles.role_name
    FROM		panda_people, panda_people_roles, panda_roles
    WHERE		panda_people.person_id = '959'
    AND		    panda_people_roles.person_id = '959'
    AND         panda_people_roles.role_id = panda_roles.role_id
	";

$get_person = doQuery($query);
    while ($row = mysql_fetch_assoc($get_person)){
      if (!$row['title_primary']) $title= $row['role_name'];
      else $title = $row['title_primary'];
      echo "<p>";
      echo "<img src=" . $row['url_image']  ." width='150' height='175' /><br clear='all'/>" ;
      echo "</p>";
      echo "<p>";
      echo $row['allnames']."<br />";
      echo $title ."<br />";
      echo "Email: <a href='mailto:" .$row['email_address'] ."'>" .$row['email_address'] ."</a><br />";
      echo "Office: " .$row['office_primary'] ."<br />";
      echo "Phone: " .$row['phone_primary'] ."<br />";
      echo "</p>";
}
dbClose();

?>
       </div>
       </div>
      <!-- TemplateEndEditable -->
      </div>