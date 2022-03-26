<?php
require_once "../common/dbconnect.php";
require_once "../common/dbFetch.php";

class Hours {
    public $ageDirectContactId;
    public $groupDirectContactId;
    public $Teaching_and_Guidance_Lessons;
    public $Career_and_College_Counseling_Interventions;
    public $Education_Testing;
    public $Student_Scheduling_and_Academic_Planning;
    public $Student_Orientation_and_Assemblies;
    public $Professional_Service;
    public $Educational_Activities;
    public $Race_Ethnicity;
    public $Sexual_Orientation;
    public $Disability;

    public function submit($con) {
        fetch($con, "INSERT INTO hours 
            (ageDirectContactId, ageDirectContactGroupId, guidanceLessonsId, careerCounselingId, educationTestingId, academicPlanningId, assembliesId, raceCountId, sexPrefCountId, disabilityCountId, professionalServiceId, educationalActivitiesId)
            VALUES ({$this->ageDirectContactId}, {$this->groupDirectContactId}, {$this->Teaching_and_Guidance_Lessons}, {$this->Career_and_College_Counseling_Interventions}, {$this->Education_Testing}, {$this->Student_Scheduling_and_Academic_Planning},
            {$this->Student_Orientation_and_Assemblies}, {$this->Race_Ethnicity}, {$this->Sexual_Orientation}, {$this->Disability}, {$this->Professional_Service}, {$this->Educational_Activities})");
    }
}
?>